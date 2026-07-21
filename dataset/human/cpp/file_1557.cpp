#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

#define FOR(k,a,b) for(int k=(a); k<=(b); ++k)
#define IFOR(k,a,b) for(int k=(a); k>=(b); --k)
#define REP(k,a) for(int k=0; k<(a);++k)
#define IREP(k,a) for(int k=a-1; k>=(0);--k)
#define SZ(a) int((a).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define MP make_pair
#define x first
#define y second
#define INF 1000000001
#define INFLONG 1000000000000000000
#define MOD 1000000007
#define MAX 100
#define ITERS 100
#define MAXM 200000
#define MAXN 1000000
#define PI 3.1415926535897932384626
#define ERR -987654321
#define MEM(a,b) memset(a,b,sizeof(a));
#define read1(a) scanf("%d",&a)
#define read2(a,b) scanf("%d%d",&a,&b)
#define read3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define readl1(a) scanf("%lld",&a)
#define readl2(a,b) scanf("%lld%lld",&a,&b)
#define readl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int rn = uniform_int_distribution<int>(0, MAXN)(rng);

    ll n;
    cin>>n;

    int k = 0;

    FOR(i,2,n) {
        ll p = i;
        p = p*(p-1);
        if(p == n*2) {
            k = i;
            break;
        }
    }
    //cout<<k<<endl;
    
    if(n == 1) {
        cout<<"Yes"<<endl<<"2"<<endl;
        cout<<"1 1"<<endl;
        cout<<"1 1"<<endl;
    }
    else if(k == 0) cout<<"No";
    else {
        vi v[k];
        int p = 1, index = 0;
        while(index < k-1) {
            int z = k - 1 - index;
            REP(i,z) v[index].PB(p), p++;
            FOR(i,index,k-2) v[i+1].PB(v[index][i]);
            index++;
        }
        cout<<"Yes"<<endl;
        cout<<k<<endl;
        REP(i,k) {
            cout<<v[i].size()<<" ";
            REP(j,v[i].size()) cout<<v[i][j]<<" "; cout<<endl;
        }
    }
	return 0;
}
