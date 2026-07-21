#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string a[52], b[52];
    for(int i=0;i<n;++i)
        cin >> a[i];
    for(int i=0;i<m;++i)
        cin >> b[i];
    bool ok = false;
    for(int i=0;i<=n-m;++i){
        for(int j=0;j<=n-m;++j){
            bool flag = true;
            for(int y=0;y<m;++y){
                for(int x=0;x<m;++x){
                    if(a[i+y][j+x] != b[y][x]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                ok = true;
                break;
            }
        }
        if(ok)break;
    }
    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
