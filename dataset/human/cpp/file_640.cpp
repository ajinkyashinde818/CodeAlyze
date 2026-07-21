#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;
ll SUM(ll n){
    ll ans=0;
    for(ll i=1;i<=n;i++)ans+=i;
    return ans;
}

int main(){
    int R,G,B,N; cin >> R >> G >> B >> N;
    ll count=0;
    int r=0;
    while(N-r*R>=0){
        int g=0;
        while(N-r*R-g*G>=0){
            if((N-r*R-g*G) % B == 0){count++;}
            g++;
        }
        r++;
    }
    cout << count << endl;
}
