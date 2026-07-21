#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<math.h>
#include <map>
using namespace std;
typedef long long int ll;
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define all(u) u.begin(),u.end()
#define pl pair<ll,ll>
#define fi first
#define se second
#define inf 1000000007
#define mp(a,b) make_pair(a,b)

ll R,G,B,N;

int main() {
    cin >> R >> G >> B >> N;
    ll ans = 0;
    rep(i,3010){
        rep(j,3010){
            if ((N-R*i-G*j) >= 0 && (N-R*i-G*j)%B == 0) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
