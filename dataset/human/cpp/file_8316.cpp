#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    int n,m; cin >> n >> m;
    vector<string> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    // 左上(i,j)
    for (int i = 0; i <= n-m; i++) {
        for (int j = 0; j <= n-m; j++) {
            //printf("(%d,%d)\n", i,j);
            bool flag = true;
            for (int s = 0; s < m; s++) {
                if (strncmp(&a[i+s][j], &b[s][0], m) != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}
