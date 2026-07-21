#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N), B(M);
  
  string s;
  for(int i = 0; i < N; i++){
    cin >> s;
    for(int j = 0; j < N; j++){
      if(s[j] == '.'){
        A[i].push_back(0);
      }else{
        A[i].push_back(1);
      }
    }
  }

  for(int i = 0; i < M; i++){
    cin >> s;
    for(int j = 0; j < M; j++){
      if(s[j] == '.'){
        B[i].push_back(0);
      }else{
        B[i].push_back(1);
      }
    }
  }

  bool ok = false;
  for(int i = 0; i < N-M+1; i++){
    for(int j = 0; j < N-M+1; j++){
      bool tmp_ok = true;
      for(int x = 0; x < M; x++){
        for(int y = 0; y < M; y++){
          if(A[i+x][j+y] != B[x][y]){
            tmp_ok = false;
          }
        }
      }
      if(tmp_ok){
        ok = true;
        break;
      }            
    }
  }

  if(ok){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
