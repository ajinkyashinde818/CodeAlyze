#include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int n, m; cin >> n >> m;
      vector<string> a(n), b(n);
      for (int i = 0; i < n; ++i) cin >> a[i];
      for (int i = 0; i < m; ++i) cin >> b[i];
      
      for (int i = 0; i <= n - m; ++i)
        for (int j = 0; j <= n - m; ++j)
        {
          bool f = true;
          for (int s = 0; s < m && f; ++s)
            for (int t = 0; t < m && f; ++t)
              if (a[i + s][j + t] != b[s][t])
                f = false;
          
          if (f) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      
      cout << "No" << endl;
    }
