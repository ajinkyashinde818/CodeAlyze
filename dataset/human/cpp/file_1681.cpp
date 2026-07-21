#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n) {
      cout << "Yes\n" << n << '\n';

      vector<int> ans[n+1]; int k = 1;
      for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                  ans[i].push_back(k);
                  ans[j].push_back(k);
                  k++;
            }
      }

      for (int i = 1; i <= n; i++) {
            cout << n-1 << ' ';
            for (int j: ans[i]) cout << j << ' ';
            cout << '\n';
      }
      exit(0);
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      for (int i = 1; i <= 1000; i++) {
            if (i*(i-1)/2 == n) {
                  solve(i);
            }
      }

      cout << "No";

      return 0;
}
