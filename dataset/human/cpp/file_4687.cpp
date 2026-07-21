#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = int (1e9) + int (1e5);
const ll INFL = ll(2e18) + ll(1e10);
const ui MOD = 1E9 + 7;
const double EPS = 1e-9;
#define FOR(i,n) for (int i=0;i<(n);++i)
#define ROF(i,x) for(int i = (x) ; i >= 0 ; --i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define ODD(x) ( ((x)&1)==0?0:1 )
#define SIGN(x) ( ((x) > 0) - ((x) < 0)  )
#define dbg(x) cerr << #x"= " << x << endl

std::mt19937_64  generator(std::chrono::system_clock::now().time_since_epoch().count());

inline ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return a ? gcd(b%a, a): b; }
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }


void READ(bool _local){
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _DEBUG
    if (_local)
        freopen ("in.txt", "r", stdin);
#endif
}

int main() {
    READ(0);
    int n,r;cin>>n>>r;
    if (n>=10) cout << r;
    else{
        cout << r + 100*(10-n);
    }


    return 0;
}
