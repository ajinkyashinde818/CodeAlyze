#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    bool flag;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a.at(i);
    for (int i = 0; i < m; ++i) cin >> b.at(i);
    for (int i = 0; i < n - m + 1; ++i) {
        for (int j = 0; j < n - m + 1; ++j) {
            flag = true;
            for (int di = 0; di < m; ++di) for (int dj = 0; dj < m; ++dj) flag &= b.at(di).at(dj) == a.at(i + di).at(j + dj);
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
