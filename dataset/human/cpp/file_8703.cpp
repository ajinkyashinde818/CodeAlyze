#include <bits/stdc++.h>

using namespace std;

vector<string> im, pat;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    im.resize(n);
    for (int i = 0; i < n; i++) cin >> im[i];
    pat.resize(m);
    for (int i = 0; i < m; i++) cin >> pat[i];
    for (int sx = 0; sx <= n - m; sx++) {
        for (int sy = 0; sy <= n - m; sy++) {
            bool ok = true;
            for (int i = 0; i< m && ok; i++) {
                for (int j = 0; j < m && ok; j++) {
                    if (im[sx + i][sy + j] != pat[i][j]) {
                        ok = false;
                    }
                }
            }
            if (ok ) {
                cout << "Yes\n";
                exit(0);
            }
        }
    }
    cout << "No";
    exit(0);
}
