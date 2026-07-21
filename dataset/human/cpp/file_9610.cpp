#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    string a[n+10];
    string b[m+10];
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }
    for(ll i=0;i<m;++i){
        cin>>b[i];
    }

    bool flag;
    string ans="No";
    ll sa=n-m+1;

    for(ll i=0;i<sa;++i){
        for(ll j=0;j<sa;++j){
            flag=true;
            if(a[i][j]==b[0][0]){

                for(ll k=0;k<m;++k){
                    for(ll l=0;l<m;++l){
                        if(a[i+k][j+l] != b[k][l]){
                            flag=false;
                        }
                    }
                }
                if(flag){
                    ans="Yes";
                    break;
                }

            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
