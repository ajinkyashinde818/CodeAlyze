#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    char imgA[n][n], imgB[m][m];
    for (int i = 0; i < n; i++) {
        string a; cin >> a;
        for (int j = 0; j < n; j++) {
            imgA[i][j] = a[j];
        }
    }
    for (int i = 0; i < m; i++) {
        string b; cin >> b;
        for (int j = 0; j < m; j++) {
            imgB[i][j] = b[j];
        }
    }

    for (int iA = 0; iA + m - 1 < n; iA++) {
        for (int jA = 0; jA + m - 1 < n; jA++) {
            bool matched = true;

            for (int iB = 0; iB < m; iB++) {
                for (int jB = 0; jB < m; jB++) {
                    matched &= imgA[iA + iB][jA + jB] == imgB[iB][jB];
                }
            }

            if (matched) {
                cout << "Yes" << endl; 
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
