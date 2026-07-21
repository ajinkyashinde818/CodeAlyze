#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, M;
char A[200][200], B[200][200];
bool ans = false;

int Solve(int I, int J){
  for (int i = 0; i < M; i++){
    for (int j = 0; j < M; j++){
      if (B[i][j] != A[I + i][J + j]) return 0;
    }
  }
  ans = true;
  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < M; i++){
    for (int j = 0; j < M; j++){
      cin >> B[i][j];
    }
  }

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      Solve(i, j);
    }
  }

  if (ans) Yes();
  else No();

  return 0;
}
