#include <bits/stdc++.h>

using namespace std;
const int N = 100;
bool A[N][N];
bool B[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            A[i][j] = s[j] == '.' ? true : false;
        }
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            B[i][j] = s[j] == '.' ? true : false;
        }
    }
    for (int i = 0; i + m <= n; i++) {
        for (int j = 0; j + m <= n; j++) {
            bool res = true;
            for (int u = 0; u < m; u++) {
                for (int v = 0; v < m; v++) {
                    if (B[u][v] != A[i + u][j + v]) {
                        res = false;
                        break;
                    }
                }
                if (!res)
                    break;
            }
            if (res) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}
