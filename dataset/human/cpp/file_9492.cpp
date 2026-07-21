#include <iostream>

using namespace std;

char a[50][50], b[50][50];
int n, m;

bool solve(int x, int y) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            if (b[i][j] != a[i + y][j + x]) return false;
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
    for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) cin >> b[i][j];
    int maxDiff = n - m;
    for (int x = 0; x <= maxDiff; ++x)
        for (int y = 0; y <= maxDiff; ++y) {
            if (solve(x, y)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    cout << "No" << endl;
}
