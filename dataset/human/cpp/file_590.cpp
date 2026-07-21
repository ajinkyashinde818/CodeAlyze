#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm> 
#include<climits>
#include<stack>
#include<queue>
#include<set>
#include<cctype>
#include<bitset> 
#include<type_traits>
#include<numeric>
#include<array>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<int,int> P_ii;
typedef pair<double,double> P_dd;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}

template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

const int mod = 1000000007;
const int MOD = 1000000007;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;

void addM(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mulM(long long &a, long long b) {
    a = ((a%MOD)*(b%MOD))%MOD ;
}

// a^b mod M
ll myPow(ll a,ll b,ll M) {
    ll ret = 1;
    ll tmp = a;
    while(b>0) {
        if((b&1)==1) ret = (ret * tmp) % M;
        tmp = (tmp * tmp) % M;
        b = b>>1;
    }
    return ret;
}

 // nCk mod M
ll nCk(ll n,ll k,ll M) {
    ll ret = 1;
    ll mi = min(k, n-k);
    for(ll i=1;i<=mi;i++) {
        ret = (ret * myPow(i,M-2,M)) % M;
    }
    for(ll i=n-mi+1;i<=n;i++) {
        ret = (ret * i) % M;
    }
    return (ll)ret;
}

int main(){
    int R,G,B,N;cin >> R >> G >> B >> N;

    int ans=0;
    rep(r,0,N/R+1) rep(g,0,N/G+1) {
        if((N-r*R-g*G)%B==0) {
            int b = (N-r*R-g*G)/B;
            if(b>=0) ans++;
        }
    }

    pl(ans)

    return 0;
}
