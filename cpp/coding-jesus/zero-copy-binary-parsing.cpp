#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

/* PROBLEM SUMMARY
 * We need to parse a binary stream of market data messages and calculate
 * the total trade volume of all Trade messages (Type 2). The binary stream
 * consists of messages that are 17 bytes long, with specific fields for type,
 * symbol, price, and quantity.
 * The key challenge is to efficiently parse the binary data. There isn't a good
 * slice operator in c++, we would love to do something like data[i:i+17], but
 * we cant because of alignment issues, and we want to avoid copying data.
 * memcpy is designed to be fast and handle unaligned mem access.
 *
 * memcpy syntax:
 * void* memcpy(void* dest, const void* src, size_t n);
 */

template <typename T> class Span {
  const T *ptr_;
  size_t len_;

public:
  Span(const T *ptr, size_t len) : ptr_(ptr), len_(len) {}
  const T &operator[](size_t i) const { return ptr_[i]; }
  size_t size() const { return len_; }
  const T *data() const { return ptr_; }
};

class MarketDataParser {
public:
  /**
   * Parses the binary buffer and calculates total trade volume.
   *
   * @param data A read-only view of the raw binary stream.
   * @return The sum of (Price * Quantity) for all Trade messages (Type 2).
   */
  double parse(Span<const uint8_t> data) {
    double total_volume = 0.0;

    // TODO: Iterate through the buffer in 17-byte chunks
    // Extract fields using std::memcpy to avoid alignment issues
    const int msg_size = 17;
    size_t cur = 0;

    while (cur + msg_size <= data.size()) {
      uint8_t type;
      std::memcpy(&type, data.data() + cur, 1);
      if (type == 2) {
        double price;
        uint32_t qty;
        std::memcpy(&price, data.data() + cur + 5, 8);
        std::memcpy(&qty, data.data() + cur + 13, 4);
        total_volume += price * qty;
      }
      cur += msg_size;
    }

    return total_volume;
  }
};

int main() {
  std::vector<uint8_t> binary_data = {
      // type 1
      1, 0, 0, 0, 0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
      0x3F,                   // price = 1.0
      0x01, 0x00, 0x00, 0x00, // qty = 1

      // type 2
      2, 0, 0, 0, 0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24,
      0x40,                   // price = 10.0
      0x05, 0x00, 0x00, 0x00, // qty = 5

      // type 2
      2, 0, 0, 0, 0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8,
      0x3F,                  // price = 1.5
      0x0A, 0x00, 0x00, 0x00 // qty = 10
  };

  MarketDataParser parser;
  Span<const uint8_t> data_span(binary_data.data(), binary_data.size());
  double total_volume = parser.parse(data_span);
  std::cout << "Total Trade Volume: " << total_volume << std::endl;
}
