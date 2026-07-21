#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    ll n,c;
    cin >> n >> c;
    vector<ll> x(n),v(n),y(n),a(n),b(n),l(n),r(n);
    rep(i,n)cin >> x[i] >> v[i];
    rep(i,n)y[i] = c-x[i];
    a[0] = v[0]-x[0];
    rep(i,n-1){
        a[i+1] = a[i] + v[i+1] - x[i+1]+ x[i];
    }
    b[n-1] = v[n-1]-y[n-1];
    for(int i=n-2;i>=0;i--){
        b[i] = b[i+1] + v[i] - y[i] + y[i+1]; 
    } 
    l[0] = max((ll)0,a[0]);
    for(int i=1;i<n;i++){
        l[i] = max(l[i-1],a[i]);
    }
    r[n-1] = max((ll)0,b[n-1]);
    for(int i=n-2;i>=0;i--){
        r[i] = max(r[i+1],b[i]);
    }
    ll ans = 0;
    rep(i,n){
        ans = max(ans,a[i]);
        ans = max(ans,b[i]);
        if(i!=n-1)ans = max(ans,a[i]+r[i+1]-x[i]);
        if(i!=0)ans = max(ans,b[i] + l[i-1]-y[i]);
    }
    cout << ans << endl;
    return 0;
}
