#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pii> vpii;
typedef vector<pair<ll,ll> > vpll;
typedef vector<vector<pair<ll,ll> > > vvpll;
typedef vector<bool> vb;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<ll,ll> mll;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) x.begin() , x.end()
#define pb push_back
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define F first
#define S second
#define left (node << 1)
#define right (node << 1) + 1
// #define mod 998244353
#define mod 1000000007 

#define trace1(x)                       cerr<<#x<<": "<<x<<endl
#define trace2(x, y)                    cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)                 cerr<<#x<<": " <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(x, y, z , t)             cerr<<#x<<": " <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<" | "<<#t<<": "<<t<<endl
#define trace5(x, y, z , t , u)         cerr<<#x<<": " <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<" | "<<#t<<": "<<t<<" | "<<#u<<": "<<u<<endl
#define trace6(x, y, z , t , u , v)     cerr<<#x<<": " <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<" | "<<#t<<": "<<t<<" | "<<#u<<": "<<u<<" | "<<#v<<": "<<v<<endl

#define repa(i,sta,end,inc) for(int i = sta ; i <= end ; i += inc)
#define repb(i,sta,end,inc) for(int i = sta ; i >= end ; i -= inc)

ll power(ll x , ll y , ll z){ll res = 1;x %= z;while(y){if(y&1){res = res * x % z;}x = x*x % z;y /= 2;}return res%z;}
ll gcd(ll a , ll b){return (b == 0 ? a : gcd(b , a % b));}

void solve(){
    int n , r;
    cin >> n >> r;
    if(n >= 10){
        cout << r << endl;
    }
    else {
        cout << r + 100 * (10 - n) << endl;
    }
}


int main(){
    FIO;
    int tc = 1;
    // cin >> tc;
    repa ( i , 1 , tc , 1){
        solve();
    }
    return 0;
}
