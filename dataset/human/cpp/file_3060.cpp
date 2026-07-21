#include"bits/stdc++.h"
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a;
  int neg_cnt = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp < 0) {
      neg_cnt++;
      tmp = -tmp;
    }
    a.push_back(tmp);
  }

  long long ans = 0;
  sort(a.begin(), a.end());
  for (int t: a) { ans += t; }
  if (neg_cnt % 2) ans -= a[0] * 2;
  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}
