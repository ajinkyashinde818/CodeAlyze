#include <bits/stdc++.h>
using namespace std;

string a[50];
string b[50];
int n, m;

bool include_pic_b(int i, int j)
{
    for (int y = 0; y < m; y++) {
        if (a[y + i].substr(j, m) != b[y]) {
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            if (include_pic_b(i, j)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
