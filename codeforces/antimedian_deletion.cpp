#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    // read permutation, but we don't actually need the values
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
    }

    if (n == 1) {
      cout << 1 << '\n';
    } else {
      for (int i = 0; i < n; i++) {
        cout << 2 << (i + 1 == n ? '\n' : ' ');
      }
    }
  }

  return 0;
}
