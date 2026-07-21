#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> a, b;

bool chk(int x, int y)
{
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[x + i][y + j] != b[i][j]) return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    bool f = false;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    for (int i = 0; i < (n - m + 1); ++i) {
        for (int j = 0; j < (n - m + 1); ++j) {
            if (a[i][j] == b[0][0]) f = chk(i, j);
            if (f) break;
        }
        if (f) break;
    }
        

    if (f) cout << "Yes" << endl;
    else cout << "No" << endl;
            
    return 0;
}
