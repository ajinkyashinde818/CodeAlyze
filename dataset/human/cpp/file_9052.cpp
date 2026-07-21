#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for(auto& e : a) cin >> e;
    for(auto& e : b) cin >> e;
    
    for (int i = 0; i < n-m+1; i++) {
        for (int j = 0; j < n-m+1; j++) {
            size_t idx = a[i].find(b[0], j);
            if (idx == string::npos) continue;
            
            bool flg = true;
            for (int k = 1; k < m; k++) {
                if (a[i+k].find(b[k], j) != idx) {
                    flg = false;
                    break;
                }
            }
            if (flg) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}
