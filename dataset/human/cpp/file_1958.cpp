// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector <ll> vec;
typedef pair <ll, ll> pr;
typedef pair <ll, pr> pr2;
typedef map <ll, vector<ll> > mv;

const int MX = 2e6+10;
const int mod = 998244353;
const ll inf = 1LL << 62;

int dx4[] = { 0, 0, -1, 1 };
int dy4[] = { 1, -1, 0, 0 };

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

// TOOLS
#define LCM(a,b)        (a / __gcd(a,b) ) *b
#define gcd(a,b)        __gcd(a,b)
#define all(x)          (x).begin(), (x).end()
#define mem(a, n)       memset(a, n, sizeof(a))
#define for1(i, n)      for(int i=1; i<=n; i++)
#define for0(i, n)      for(int i=0; i<n; i++)
#define rof0(i, n)      for(int i=n-1; i>=0; i--)
#define rof1(i, n)      for(int i=n; i>=1; i--)
#define forab(i, a, b)  for(int i=a; i<=b; i++)
#define rofab(i, a, b)  for(int i=b; i>=a; i--)
#define pb              push_back
#define pbb             pop_back

// CIN/COUT
#define sin(s)          getline(cin, s)
#define case(a)              cout << "Case "<<(a)<<": "

// SCANF/PRINTF
#define fYES            printf("YES\n")
#define fNO             printf("NO\n")
#define Scf(a)          scanf("%lld", &a)
#define Scf2(a, b)      scanf("%lld %lld", &a, &b)
#define Scf3(a, b, c)   scanf("%lld %lld %lld", &a, &b, &c)
#define Scf4(a,b,c,d)   scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define Pnf(a)          printf("%lld\n", a)
#define Pnf2(a, b)      printf("%lld %lld\n", a, b)
#define Pnf3(a, b, c)   printf("%lld %lld %lld\n", a, b, c)
#define Bug(n)          printf(">> %lld <<\n", n)

// OTHERS
#define sz(n)          n.size()
#define clr(v)          v.clear()
#define min3(a, b, c)   min(a, min(b, c))
#define max3(a, b, c)   max(a, max(b, c))
#define in              freopen("input.txt", "r", stdin)
#define out             freopen("output.txt", "w", stdout)
#define FastIO          { ios_base::sync_with_stdio(false); cin.tie(0); }
#define F               first
#define S               second
#define mpp             make_pair
//End
int mark[100010],mark1[100010];
map<ll,vector<ll> > mp,mp1;
priority_queue<pair<ll,ll> > PQ;
vector<ll > v,v1;
set<int>S;
int n;
ll dp[200001][3];
ll Dp(int i,int last)
{
    ll temp=0,temp1=0;
    if(i==n-1)
    {
        if(last==0)
            return v[n-1];
        else
            return (v[n-1]*-1);
    }
    if(dp[i][last]!=-1)
        return dp[i][last];
    if(last==0)
    {
        temp=v[i]+Dp(i+1,0);
        temp1=(v[i]*-1)+Dp(i+1,1);
    }
    else
    {
        temp=(v[i]*-1)+Dp(i+1,0);
        temp1=v[i]+Dp(i+1,1);
    }
    dp[i][last]=max(temp,temp1);
    return dp[i][last];
}
int main()
{

    ll m, k, q, t, cnt = 0, sum = 0,ans=0, mx = -inf, mn = inf, a, b, c,d,e,f,g,h,i,j,x, y, z,temp, temp1;
    string s, s1, s2, s3,s4,s5,s6,s7;
    cin>>n;
    for0(i,n)
    {
        cin>>a;
        v.pb(a);
    }
    for0(i,n+5)
    {
        dp[i][0]=-1;
        dp[i][1]=-1;
    }
    cout<<Dp(0,0)<<endl;
    return 0;
}
