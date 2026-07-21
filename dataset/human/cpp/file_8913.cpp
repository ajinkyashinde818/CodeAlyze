#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ,m, k, l;
    cin >> n >> m;
    if(n < m) {
        cout << "No" << "\n";
        return 0;
    } else {
        string a[50];
        string b[50];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];
        for(int ly = 0; ly < n-m+1; ly++) {
            for(int lx = 0; lx < n-m+1; lx++) {
                bool flag = true;
                for(int y = 0; y < m; y++) {
                    for(int x = 0; x < m; x++) {
                        if(a[ly+y][lx+x] != b[y][x]) {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) break;
                }
                if(flag) {
                    cout << "Yes" << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "No" << "\n";
    return 0;
}
