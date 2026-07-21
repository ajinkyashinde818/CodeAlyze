#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

char a[100][100],b[100][100];

int main(void){
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    bool ans=false;
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            bool kari=true;
            for(int h=0;h<m;h++){
                for(int w=0;w<m;w++){
                    if(a[i+h][j+w]!=b[h][w]){
                        kari=false;
                    }
                }
            }
            if(kari) ans=true;
        }
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
