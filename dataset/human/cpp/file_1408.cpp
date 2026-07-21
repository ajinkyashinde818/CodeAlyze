#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX;
const ll MOD = 1e9+7;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;cin>>N;
  ll k=1;
  for(;k*(k-1)/2<N;k++);
  if(k*(k-1)/2!=N){
    cout << "No" << endl;
    return 0;
  }
  vector<vint> S(k);
  int cnt=1;
  repeat(i,k){
    repeat(j,i){
      S[i].push_back(cnt);
      S[j].push_back(cnt);
      cnt++;
    }
  }
  cout << "Yes" << endl;
  cout << k << endl;
  repeat(i,k){
    cout << k-1;
    repeat(j,k-1){
      cout << " " << S[i][j];
    }
    cout << endl;
  }
  return 0;
}
