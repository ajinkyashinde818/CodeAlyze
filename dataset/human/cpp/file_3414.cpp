#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n);

  int countNeg = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    if (a[i] <= 0) countNeg++;
  }

  ll ans = 0;
  int minn = 1000000001;
  for (int i = 0; i < n; i++) {
    ans += abs(a[i]);
    minn = min(minn, abs(a[i]));
  }

  // - が偶数なら全部+にできる
  // 奇数なら一個だけ-になるのでabsが最小のものを-にする

  if (countNeg % 2 != 0) {
    ans -= minn * 2;  // すでに最小のものもansに計上されているので*2して引く
  }

  cout << ans << endl;

  return 0;
}
