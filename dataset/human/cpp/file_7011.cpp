#include<bits/stdc++.h>

using namespace std;

using LL  = long long;
using LD  = long double;
using ULL = unsigned long long;
using VI   = vector<int>;
using VLL = vector<long long>;
using VULL= vector<unsigned long long>;
using VS  = vector<string>;
using VB  = vector<bool>;
using VC  = vector<char>;
using PII = pair<int, int>;
using PLL = pair<long long, long long>;
using VPII = vector<pair<int, int>>;
using VPLL = vector<pair<long long, long long>>;
using VPULL = vector<pair<unsigned long long, unsigned long long>>;
using VVI = vector<vector<int>>;
using VVLL = vector<vector<long long>>;
using MII = map<int, int>;
using MLL = map<long long, long long>;
using SLL = set<long long>;
using SI = set<int>;
using PQI = priority_queue<int>;

#define FF                             first
#define SS                             second
#define PB                             push_back
#define PF                             push_front
#define MP                             make_pair
#define all(a)                         (a).begin(), (a).end()
#define dec(n)                         cout<<fixed<<setprecision(n);
#define f(i, n)                        for(LL i=0; i<(LL)n; i++)
#define fr(i,n)                        for(LL i=(LL)(n-1); i>=0; i--)
#define fa(i, a, n)                     for(LL i=(LL)a; i<(LL)n; i++)
#define fra(i, a, n)                    for(LL i=(LL)(n-1); i>=a; i--)
#define fsort(a)                       sort(a.begin(), a.end())
#define rsort(a)                       sort(a.rbegin(), a.rend())
#define out(a)                         for(auto x: a) cerr<<x<<" "; debug();



#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);srand(time(NULL))

template<class T>  T maxT(T a, T b){return (a>b?a:b);}
template<class T>  T minT(T a, T b){return (a<b?a:b);}
template<class T>  void setmax(T &a, T b){a=(a>b ?a:b);}
template<class T>  void setmin(T &a, T b){a=(a<b ?a:b);}

void fileio(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
}

void ofileio(){
  freopen("input.txt","r", stdin);
  freopen("output.txt", "w", stdout); 
}

void clock_out(){
  cerr<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
}


void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}

template<typename... Args>
void readln(Args&... args)
{
    ((cin >> args), ...);
}

template<typename... Args>
void writeln(Args... args)
{
    ((cout << args << " "), ...);
}

 
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define fio() fileio()
#define ofio ofileio()
#define clock() clock_out()
#else
#define debug(...) 1
#define fio() 1
#define ofio() ofileio()
#define clock() 1
#endif

const LL MOD     = 1000000007;
const LL SIZE    = 100000;
const int INF    = 0x3f3f3f3f;
const LL LL_INF  = 0x3f3f3f3f3f3f3f3f;
const LD PI      = acos(-1);
const LL MAXN    = numeric_limits<LL>::max();

#define sz(x) (LL)(x).size()

void solve(){
   int n;
   cin>>n;
   VI a(n), b(n);
   f(i, n) cin>>a[i];
   f(i, n) cin>>b[i];

   reverse(all(b));
   int l=-1, r=-1, c=-1;
   f(i, n){
      if(a[i]==b[i] && l==-1)l=i, c=a[i];
      if(a[i]==b[i]) r=i;
   }

   // debug(l, r);

   if(c>=0){

   f(i, n){
    if(a[i]!=c && b[i]!=c && l<=r){
      // debug(b[i]);
      swap(b[i], b[l]);
      l++;
    }
   }
   }
   if(c>=0&&l<=r){
    cout<<"No\n";
    return;
   }

   cout<<"Yes\n";
   f(i, n) cout<<b[i]<<" ";


}

int main(){
  fast;
  //fio();

  LL t=1;
  //cin>>t;
  while(t--){
      solve();
  }
  clock();
  return 0;
}
