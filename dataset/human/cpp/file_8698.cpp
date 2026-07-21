#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50, MAX_M = MAX_N, INDEX = 1;

int n, m;

bool a[MAX_N + INDEX][MAX_N + INDEX], b[MAX_M + INDEX][MAX_M + INDEX];

bool isGood(int r, int c) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[r + i - 1][c + j - 1] != b[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s;

        cin >> s;

        for (int j = 1; j <= n; j++) {
            a[i][j] = s[j - 1] == '#';
        }
    }

    for (int i = 1; i <= m; i++) {
        string s;

        cin >> s;

        for (int j = 1; j <= m; j++) {
            b[i][j] = s[j - 1] == '#';
        }
    }

    for (int i = 1; i + m - 1 <= n; i++) {
        for (int j = 1; j + m - 1 <= n; j++) {
            if (isGood(i, j)) {
                cout << "Yes" << endl;

                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
