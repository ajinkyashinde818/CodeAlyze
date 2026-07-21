#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char a[n][n], b[m][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    bool ans = false;
    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            bool match = true;
            for (int y = 0; y < m; y++) {
                for (int x = 0; x < m; x++) {
                    if (a[i + y][j + x] != b[y][x])
                        match = false;
                }
            }
            if (match) ans = true;
        }
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
