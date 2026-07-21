#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n-m+1; i++) {
        for (int j = 0; j < n-m+1; j++) {
            
            bool flag = false;
            for (int y = 0; y < m; y++) {
                for (int x = 0; x < m; x++) {
                    if (a.at(i+y).at(j+x) != b.at(y).at(x)) {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if (!flag) {
                cout << "Yes" << endl;
                return 0;
            }

        }
    }
    cout << "No" << endl;
}
