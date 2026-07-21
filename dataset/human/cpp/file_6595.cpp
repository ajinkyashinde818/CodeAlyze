#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

// vector確認用
template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  cout << "}";
  return os;
}

vector<ll> kai(100010);

// ====================================================================

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  // 端がW、っていう例外（0を返す）
  if (s[0] == 'W' || s[s.size() - 1] == 'W') {
    cout << 0 << endl;
    return 0;
  }

  // まず、右側の候補になるものを記録する
  vector<int> v(s.size());
  char bef = 'x';
  int res = 1, sum = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == bef)
      res *= -1;
    v[i] = res;
    bef = s[i];

    sum += v[i];
    if (sum < 0) {  // 右端の候補が多すぎるタイミングがある
      cout << 0 << endl;
      return 0;
    }
  }

  // 左端や右側の候補が全体的にみて多すぎる
  if (sum != 0) {
    cout << 0 << endl;
    return 0;
  }

  // cout << v << endl;  // 「右端」が1になってるvector

  // 階乗テーブル作成
  kai[0] = 1;
  for (int i = 1; i < kai.size(); i++) kai[i] = kai[i - 1] * i % MOD;

  // 左側の並び替えのぶんの階乗を掛ける（階乗）
  ll ans = kai[n], lcou = 0, rcou = 0;
  for (int i = 0; i < s.size(); i++) {
    if (v[i] == 1) {  // lだったら;
      lcou++;
    } else {  // rだったら
      ans = ans * (lcou - rcou) % MOD;
      rcou++;
    }
  }

  // 答えを出力
  cout << ans << endl;
}
