#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;
template<class T> using ttt = tuple<T,T>;
using tii = tuple<int,int>;
using tiii = tuple<int,int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define DIV int(1e9+7)
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
//const double PI = M_PI;  
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}
 
/*Coding Space*/
ll used[100001] = {};
int main(){
  ll n; cin >> n;
  ll t = 0;
  rep(i,100001)if(1LL * (i+1)*i/2 == n) t = i+1;
  if(!t){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
    cout << t << endl;
    rep(i,t){
      cout << t-1 << " ";
      int cnt = 0;
      int index = 1;
      vt<int> v;
      rep(x,100001){
        if(cnt == t - 1) break;
        if(used[x+1] == index){
          v.pb(x+1); used[x+1] = LLINF; index++; cnt++;
        }else if(used[x+1] == 0){
          v.pb(x+1); used[x+1] = i+1; cnt++;
        }
      }
      rep(ii,t-1) cout << v[ii] << (ii == t-2?"\n":" ");
    }
  }
}
