#include <iostream>
using namespace std;

int find_divisors(int n) {
  int count = 0;
  for (int i = 1; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
      count++;
      if (i * i != n) {
        count++;
      }
    }
  }
  return count;
}

void print_mixed(int x, int y) {
  for (int i = 0; i < x; i++) {
    cout << 1 << ' ';
  }
  for (int i = 0; i < y; i++) {
    cout << -1 << (i + 1 == y ? '\n' : ' ');
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    // read two numbers
    int x, y;
    cin >> x >> y;

    if (x == y) {
      cout << 1 << '\n';
    } else {
      cout << find_divisors(std::abs(x - y)) << '\n';
    }
    print_mixed(x, y);
  }
  return 0;
}
