#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;


int main(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=0;i<n;i++){
        ll A;
        cin>>A;
        a[i+1]=a[i]+A;
    }
    ll ans=INF;
    for(int i=1;i<n;i++){
        ll x=a[i];
        ll y=a[n]-a[i];
        ans=min(ans,llabs(x-y));
    }
    cout<<ans<<endl;
}
