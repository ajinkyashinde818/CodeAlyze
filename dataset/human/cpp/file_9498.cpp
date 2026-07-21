#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {        
    int n, m;
    cin >> n >> m;
    vector<string> a, b;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        b.push_back(s);
    }
    for (int i = 0; i + m - 1 < n; i++) {
        for (int j = 0; j + m - 1 < n; j++) {
            int flag = 1;
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < m; y++) {
                    if (b[x][y] != a[i + x][j + y]) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag == 1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
