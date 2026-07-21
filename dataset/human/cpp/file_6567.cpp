#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<algorithm> // sort
#include<map> // pair
#include<cmath>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
const ll mod = 1e9+7;
const int INF = 1e9;
const ll INFLONG = 1e18;
vector<ll> vec((ll)2e5,0);
vector<ll> isleft((ll)2e5,0);
int main(){
  ll n;
  string s;
  cin >> n;
  cin >> s;
  ll lefcou = 0;
  ll sum = 1;
  rep(i,2*n){
    //cout << lefcou << " ";
    if(lefcou < 0){sum = 0;break;}
    if(s[i] == 'B'){
      if(lefcou % 2 == 0){
        isleft[i] = 1;
        lefcou++;
      }else{
        isleft[i] = 0;
        sum = (sum * lefcou) % mod;
        lefcou--;
      }
    }else{
      if(lefcou % 2 == 0){
        isleft[i] = 0;
        sum = (sum * lefcou) % mod;
        lefcou--;
      }else{
        isleft[i] = 1;
        lefcou++;
      }
    }
  }
  // cout << endl;
  // rep(i,2 * n){
  //   cout << isleft[i] << " ";
  // }
  //cout << endl;
  // rep(i,2*n){
  //   cout << lefcou << " ";
  //   if(s[2*n-1-i] == 'B'){
  //     if(lefcou % 2 == 0){
  //       isleft[i] = 1;
  //       lefcou++;
  //     }else{
  //       isleft[i] = 0;
  //       sum *= lefcou % mod;
  //       lefcou--;
  //     }
  //   }else{
  //     if(lefcou % 2 == 0){
  //       isleft[i] = 0;
  //       sum *= lefcou % mod;
  //       lefcou--;
  //     }else{
  //       isleft[i] = 1;
  //       lefcou++;
  //     }
  //   }
  // }
  rep(i,n){
    sum = (sum * (i+1)) % mod;
  }
  //sum = (sum * (n*(n-1)/2%mod)) % mod;
  if(lefcou != 0){sum = 0;}
  cout << sum;
}
