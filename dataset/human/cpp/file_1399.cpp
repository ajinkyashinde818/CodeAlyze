#include <bits/stdc++.h>

using namespace std;


int n;
int e[1000][1000];
int es;

void print(int m) {
    cout << "Yes\n" << m << '\n';
    for (int i = 0; i < m; i++) {
        cout << m - 1;
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            if (!e[i][j]) {
                e[i][j] = ++es;
                e[j][i] = e[i][j];
            }
            cout << ' ' << e[i][j];
        }
        cout << '\n';
    }
}

int main() {
    cin >> n;
    for (int i = 2; i*(i-1)/2 <= n; i++) {
        if (i*(i-1)/2 == n) {
            print(i);
            return 0;
        }
    }
    cout << "No\n";
}
