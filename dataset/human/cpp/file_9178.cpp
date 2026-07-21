#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> a;
    vector<string> b;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        b.push_back(s);
    }
    for (int y = 0; y < n-m+1; ++y) {
        for (int x = 0; x < n-m+1; ++x) {
            bool found = true;
            for (int j = 0; j < m; ++j) {
                for (int i = 0; i < m; ++i) {
                    if (a[y+j][x+i] != b[j][i]) {
                        found = false;
                    }
                }
            }
            if (found) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
