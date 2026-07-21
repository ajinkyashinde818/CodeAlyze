#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    string ans = "No";
    for(auto& e : a) cin >> e;
    for(auto& e : b) cin >> e;
    for(int i = 0; i < n - m + 1; i++){
        for(int j = 0; j < n - m + 1; j++){
            bool flag = true;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(a[i+k][j+l] != b[k][l]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                ans = "Yes";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
