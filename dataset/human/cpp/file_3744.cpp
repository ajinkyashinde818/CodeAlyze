#include <bits/stdc++.h>
using namespace std;

//===============typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef map<string, int> msi;

/*
using namespace __gnu_pbds;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;
*/


//=================Constant
const ll MOD=1e9+7;
const ll inf=10000000;

//=============define
#define cln(a) memset(a,0,sizeof a);
#define clni(a) memset(a,inf,sizeof a);
#define all(x) x.begin(), x.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define pb push_back
#define sp(c,x) ((c).find(x) != (c).end())  // for set,map
#define vp(c,x) (find(all(c),x) != (c).end())  // for vector
#define uu first
#define vv second
#define fr(i,a,b) for(int i=int(a);i<int(b);++i)
#define nfr(i,a,b) for(int i= int(a);i>=int(b);--i)
#define tc cin>>t ; while(t--)
#define pc()  cout<<"Case "<<cs++<<": "

#define s2(x,y) scanf("%d %d",&x,&y)
#define s2l(x,y) scanf("%lld %lld",&x,&y)
#define s3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define s3l(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sc(x)  scanf("%d",&x)
#define sll(x)  scanf("%lld",&x)
#define pfs(x) printf("%d ",x)
#define pfl(x) printf("%d\n",x)
#define el puts("");
#define getcx() getchar()
#define IOS    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define Fl   freopen("in", "r", stdin);freopen("out","w", stdout)


//============functions
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

//============ Grid


int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0}; 

void read(){
	
	#ifndef cp		
		Fl;       	
	#endif
}

const ll N=1e5+5;


void dfs()
{

}

bool cmp()
{
    
}


vl v;
int main()
{
//		read();
			IOS;
			ll n,sm=0;
			cin>>n;
			v.resize(n);
			fr(i,0,n)
			{
				cin>>v[i];
			}

			ll x=0,mn=INT_MAX;
			for(int i=0;i<n;i++)
			{
				x+=(v[i]<0);

				v[i]=abs(v[i]);
				mn=min(mn,v[i]);
				sm+=v[i];
			}
			if(x%2)
				sm-=2*mn;
			cout<<sm<<endl;
}
