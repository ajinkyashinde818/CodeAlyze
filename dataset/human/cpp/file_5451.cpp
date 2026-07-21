#include"bits/stdc++.h"
using namespace std;

void Main() {
  int n, r;
  cin >> n >> r;
  if (n < 10) cout << r + 100 * (10 - n) << endl;
  else cout << r << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}
