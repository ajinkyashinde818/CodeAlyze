#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long int ll;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }return 0; }
#define all(a)  (a).begin(),(a).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
const ll INF =1LL << 62;

int main(){
  ll N ;
  cin >> N;
  string s ;
  cin >> s;
  char str[26] = {'a','b','c','d','e','f','g','h'
    ,'i','j','k','l','m','n','o'
    ,'p','q','r','s','t','u','v','w'
    ,'x','y','z'};
  ll res[26];
  rep(i,26)
    res[i]=1 ;
  rep(i,N){
    rep(j,26){
      if(s[i] == str[j] )
        res[j] ++;
    }
  }
  ll ans =1;
  rep(i,26){
    ans *= res[i];
    ans %= 1000000007 ;
  }
  ans --;
  if(ans ==0){
    cout << 1000000006 <<endl;
    return 0;
  }
  cout << ans <<endl;
}
