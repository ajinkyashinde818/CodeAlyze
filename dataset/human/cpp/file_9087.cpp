#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
        int n, m;
        string s;
        vector<string> a, b;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
                cin >> s;
                a.push_back(s);
        }
        for (int i = 0; i < m; i++) {
                cin >> s;
                b.push_back(s);
        }

        bool flg;
        for (int i = 0; i < n - m + 1; i++) {
                for (int j = 0; j < n - m + 1; j++) {
                        flg = true;
                        for (int k = 0; k < m; k++) {
                                for (int l = 0; l < m; l++) {
                                        if (a[i+k][j+l] != b[k][l]) {
                                                flg = false;
                                                break;
                                        }
                                }
                                if (flg == false)
                                        break;
                        }
                        if (flg == true) {
                                cout << "Yes" << endl;
                                exit(0);
                        }
                }
        }
        cout << "No" << endl;

        return 0;
}
