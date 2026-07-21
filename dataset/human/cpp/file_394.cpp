#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    ll ans=0;
    for(int i=0;i<=n/r;i++){
        for(int j=0;j<=(n-r*i)/g;j++){
            if((n-r*i-g*j)%b==0)ans++;
        }
    }
    cout<<ans<<endl;
}
