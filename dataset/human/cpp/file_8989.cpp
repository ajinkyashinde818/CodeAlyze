#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  int N, M;
  cin >> N >> M;
  char A[N][N];
  char B[M][M];
  rep(i, N)rep(j, N)cin >> A[i][j];
  rep(i, M)rep(j, M)cin >> B[i][j];
  bool ans = false;
  rep(i, max(N-M, 1)){
    rep(j, max(N-M, 1)){
      bool temp_flag = true;
      rep(k, M){
        rep(l, M){
          if (A[i+k][j+l] != B[k][l]){
            temp_flag = false;
          }
        }
      }
      if (temp_flag)ans = true;
    }
  }
  if (ans)cout << "Yes" << endl;
  else cout << "No" << endl;
}
