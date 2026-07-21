#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
#include<tuple>
#include<stdio.h>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(10)
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Q;
typedef pair<Q,ll> R;
ll longinf=1ll<<60;
int inf=1<<29;
//mleしなければぜんぶllでかく。
//↑はあんまり気にしなくていい。

int main(){
    int R,G,B,N;
    cin>>R>>G>>B>>N;
    int ans=0;
    rep0(r,N+1)rep0(b,N+1){
        int M=N-R*r-B*b;
        if(M>=0&&M%G==0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
