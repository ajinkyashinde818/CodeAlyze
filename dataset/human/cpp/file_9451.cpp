#include <bits/stdc++.h>

using namespace std;

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);

    string s1[52], s2[52];

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> s1[i];

    for(int i = 0; i < m; ++i)
        cin >> s2[i];

    int li = n - m + 1;
    for(int i = 0; i < li; ++i) {
        for(int j = 0; j < li; ++j) {
            if (s1[i][j] == s2[0][0]) {
                bool q = 1;
                for(int x = i, o = 0; x < i + m && o < m && q; ++x, ++o)
                    for(int y = j, p = 0; y < j + m && p < m && q; ++y, ++p) {
                        if (s1[x][y] != s2[o][p])
                            q = 0;
                }
                if (q) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }

    cout << "No";

    return 0;
}
