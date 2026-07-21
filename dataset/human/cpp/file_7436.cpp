#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef  pair<int,int> P;
typedef long long LL;
typedef vector<LL> VEC;


const LL INF=1<<30;
const LL MOD=1000000007;

LL gcd(LL a,LL b){
    if(b==0)return a;

    return gcd(b,a%b);
}

LL kaijo(LL n){
    LL ans=1;
    for(LL i=1;i<=n;++i){
        (ans*=i)%=MOD;
    }
    return ans;
}


int main(){
    LL n;
    cin>>n;
    LL a[200500];
    LL x=0,y=0;
    for(LL i=0;i<n;++i){
        cin>>a[i];
        y+=a[i];
    }
    LL ans=INF;
    x+=a[0];
    y-=a[0];
    if(n==2)cout<<abs(a[0]-a[1])<<endl;
    else{
    for(LL i=1;i<n-1;++i){
        y-=a[i];
        x+=a[i];
        ans=min(ans,abs(x-y));
    }
    cout<<ans<<endl;
}
}
