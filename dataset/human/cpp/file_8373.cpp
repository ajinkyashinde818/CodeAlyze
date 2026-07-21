#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char a[n][n], b[n][n];

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

    bool f = true;

    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            f = true;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if (a[k + i][l + j] != b[k][l]) {
                        f = false;
                        break;
                    }
                }
            }

            if (f) {
                cout << "Yes" << endl;
                return 0;
            }

        }
    }

    if (!f) {
        cout << "No" << endl;
    }

    return 0;
}
