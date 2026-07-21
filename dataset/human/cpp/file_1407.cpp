#include <iostream>
#include <cmath>

using namespace std;

int
main()
{
  int n;
  cin >> n;

  int k = (sqrt(8 * n + 1) + 1) / 2;
  for (--k; k * (k - 1) < 2 * n; ++k)
    ;
  if (k * (k - 1) != 2 * n) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  cout << k << '\n';
  long long m = 0;
  for (int i = 0; i < k; ++i) {
    cout << k - 1;
    long long l = i;
    for (int j = 0; j < i; ++j) {
      cout << ' ' << l;
      l += k - j - 2;
    }
    for (int j = i + 1; j < k; ++j) {
      cout << ' ' << ++m;
    }
    cout << "\n";
  };
  
  return 0;
}
