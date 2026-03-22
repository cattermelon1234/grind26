#include <iostream>
#include <thread>
#include <vector>

/* PROBLEM SUMMARY
 * We need to aggregate trade volumes from multiple different executions. If we
 * increment the volume in a shared variable, we will have contention between
 * threads. Using locks and atomics is possible but inefficient due to
 * contention. Instead, we can use thread-local storage to maintain a separate
 * volume accumulator for each thread. Each thread will add to its own local
 * accumulator, and we can retrieve the accumulated volume for each thread
 * without contention. This approach allows us to efficiently aggregate volumes
 * in a multi-threaded environment without the overhead of synchronization
 * primitives.
 */

/* NOTES
 * 1. thread_local is a storage class specifier in c++ that does exactly what it
 * says
 * 2. thread_local can only be declared as static inside of a class. If not,
 * each object will have its own thread_local, which is not what we want.
 * 3. static variables are normally not initialized inside the class, it leads
 * to compiler errors. So we either have to initialize it outside the class or
 * use inline static, which allows us to initialize it inside the class
 * definition.
 */

class VolumeAccumulator {
public:
  /**
   * Adds volume to the thread-local storage.
   */
  void add(double volume) { tls += volume; }

  /**
   * Returns the accumulated volume for the calling thread.
   */
  double getThreadLocalVolume() {
    // TODO: Implement
    return tls;
  }

private:
  inline static thread_local double tls = 0.0;
};

int main() {
  VolumeAccumulator accumulator;

  // create multiple threads to add volume concurrently
  std::vector<std::thread> threads;
  for (int i = 0; i < 5; ++i) {
    threads.emplace_back([&accumulator, i]() {
      for (int j = 0; j < 100; ++j) {
        accumulator.add(1.0); // Each thread adds 100.0 to its local storage
      }
      // Print the thread-local volume for this thread
      std::cout << "Thread " << i
                << " local volume: " << accumulator.getThreadLocalVolume()
                << std::endl;
    });
  }
  for (auto &t : threads) {
    t.join();
  }
}
