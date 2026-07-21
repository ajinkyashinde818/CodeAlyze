#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

const ll MOD = 1e9+7;

int main(){
    ll n;
    cin >> n;
    ll a[n] = {};
    ll sum = 0;
    PQll pq;
    rep(i,0,n){
        cin >> a[i];
        sum += a[i];
        pq.push(a[i]);
    }

    while(1){
        if(pq.size() < 2) break;
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        if((a+b) >= 0) break;
        else{
            sum += 2 * abs(a + b);
        }
    }

    cout << sum << endl;
}
