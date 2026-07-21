#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string a[n], b[m];
    bool match = false;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    // cout << "in" << endl;
    for (int y = 0; y < n - m + 1; y++) {
        for (int x = 0; x < n - m + 1; x++) {
            bool match_part = true;
            for (int i = 0; i < m; i++) {
                if (a[y + i].substr(x, m) != b[i]) {
                    match_part = false;
                    break;
                }
            }
            if (match_part) match = true;
        }
    }
    if (match) cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
