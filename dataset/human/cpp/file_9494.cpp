#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    string ans = "No";
    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j <= n - m; j++){
            bool f = true;
            for(int k = 0; k < m; k++){
                if(b[k] != a[i + k].substr(j, m)){
                    f = false;
                    break;
                }
            }
            if(f) ans = "Yes";
        }
    }
    cout << ans << endl;
}
