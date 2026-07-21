#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repl(i, n) for(LL i = 0; i < (LL)(n); i++)

int main(void){
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);

  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  bool exist = false;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      bool match = true;
      for (int k = 0; k < m; k++) {
        if (!match) break;
        for (int l = 0; l < m; l++) {
          if (a[i+k][j+l] != b[k][l]) {
            match = false;
            break;
          }
        }
      }

      if (match) {
        exist = true;
        break;
      }
    }
  }

  if (exist) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
