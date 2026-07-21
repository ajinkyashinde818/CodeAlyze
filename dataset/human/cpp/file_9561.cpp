//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 50;

char a[1 + MAXN][1 + MAXN], b[1 + MAXN][1 + MAXN];

bool Check(int n, int m, int x, int y) {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            if (b[i][j] != a[x + i - 1][y + j - 1])
                return false;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] + 1;
    for (int i = 1; i <= m; i++)
        cin >> b[i] + 1;
    for (int i = 1; i + m - 1 <= n; i++)
        for (int j = 1; j + m - 1 <= n; j++)
            if (Check(n, m, i, j)) {
                cout << "Yes\n";
                return 0;
            }
    cout << "No\n";
    return 0;
}
