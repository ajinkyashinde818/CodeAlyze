#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

char a[64][64], b[64][64];

void yes() {
  cout << "Yes";
  exit(0);
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  for(int i = 0; i < m; ++i)
    cin >> b[i];

  for(int i = 0; i + m - 1 < n; ++i) {
    for(int j = 0; j + m - 1 < n; ++j) {
      bool can = true;

      for(int x = 0; can && x < m; ++x)
        for(int y = 0; can && y < m; ++y)
          if(a[i+x][j+y] != b[x][y])
            can = false;

      if(can) yes();
    }
  }

  cout << "No";
}
