#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#include <bitset>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}

int main(){
  int N; cin >> N;
  vector<ll> A(N); rep(i,N) cin >> A[i];
  int mincnt = 0;
  rep(i,N) if(A[i]<0) mincnt++;

  ll ans = 0;
  if(mincnt%2==1){
    rep(i,N) A[i] = abs(A[i]);
    sort(all(A));
    A[0]*=-1;
    rep(i,N) ans += A[i];
  }
  else{
    rep(i,N) ans += abs(A[i]);
  }
  cout << ans << endl;
  return 0;
}
