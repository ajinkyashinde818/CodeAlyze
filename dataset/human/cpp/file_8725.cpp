#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    short n,m;
    cin>>n>>m;
    string a[n],b[m],ans="Yes";
    bool f=0;
    for (int i = 0; i < n; i++)cin>>a[i];
    for (int i = 0; i < m; i++)cin>>b[i];
    for (int k = 0; k < n-m+1; k++){
        for (int l = 0; l < n-m+1; l++){
            bool f1=1;
            for (int i = 0; i < m; i++){
                for (int j = 0; j < m; j++){
                   if(b[i][j]!=a[i+k][j+l])f1=0;
                }
            }
            f|=f1;
        }
    }
    cout<<(f?"Yes":"No")<<'\n';
}
