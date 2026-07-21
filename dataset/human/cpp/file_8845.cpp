#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char x;
            cin >> x;
            if(x=='#') a.at(i).at(j)=true;
        }
    }
    vector<ll> b(m);
    for(int i = 0; i < m; i++) {
        ll x=0;
        for(int j = 0; j < m; j++) {
            x *= 2;
            char y;cin >> y;
            if(y=='#') x ++;
        }
        b[i]=x;
    }
    
    for(int i = 0; i < n-m+1; i++) {
        for(int j = 0; j < n-m+1; j++) {
            vector<ll> x(m);
            for(int k = 0; k < m; k++) {
                ll y=0;
                for(int l = 0; l < m; l++) {
                    y *= 2;
                    bool z=a.at(i+k).at(j+l);
                    if(z) y++;
                }
                x[k]=y;
            }
            if(x==b){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    

    return 0;
}
