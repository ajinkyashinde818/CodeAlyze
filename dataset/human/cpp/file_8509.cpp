#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    bool exist = false;
    for (int dy = 0; dy <= n-m && !exist; dy++) {
        for (int dx = 0; dx <= n-m && !exist; dx++) {
            bool match = true;
            for (int y = 0; y < m && match; y++) {
                for (int x = 0; x < m && match; x++) {
                    if (a[y+dy][x+dx] != b[y][x]) match = false;
                }
            }
            if (match) exist = true;
        }
    }

    cout << (exist ? "Yes" : "No") << endl;
}
