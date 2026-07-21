#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int ans=0;
    rep(i,3030)rep(j,3030){
        int sum=n-r*i-g*j;
        if(sum>=0&&sum%b==0)++ans;
    }
    cout<<ans<<endl;
    return 0;
}
