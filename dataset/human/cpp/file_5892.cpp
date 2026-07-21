#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  int N; ll C; cin >> N >> C;

  vector <ll> X(N + 2), V(N + 2);

  for (int i = 1; i <= N; i++){
    cin >> X[i] >> V[i];
  }
  X[N + 1] = C;

  vector <ll> sumV(N + 2), RsumV(N + 2);
  for (int i = 1; i < N + 2; i++){
    sumV[i] = sumV[i - 1] + V[i];
  }

  for (int i = N; i >= 0; i--){
    RsumV[i] = RsumV[i + 1] + V[i];
  }
  
  ll ans = 0;

  for (int i = 0; i < N + 2; i++){
    ans = max(ans, sumV[i] - X[i]);
  }
  for (int i = N + 1; i >= 0; i--){
    ans = max(ans, RsumV[i] - (C - X[i]));
  }
  

  // 時計回り -> 反時計回り
  vector <ll> L1(N + 2), R1(N + 2);
  for (int i = 0; i < N + 2; i++){
    L1[i] = sumV[i] - 2 * X[i];
  }
  
  for (int i = N + 1; i >= 0; i--){
    R1[i] = RsumV[i] - (C- X[i]);
    if (i < N + 1){
      R1[i] = max(R1[i], R1[i + 1]);
    }
  }

  for (int i = 0; i < N + 1; i++){
    ans = max(ans, L1[i] + R1[i + 1]);
  }

  // 反時計周り -> 時計回り

  vector <ll> L2(N + 2), R2(N + 2);
  for (int i = N + 1; i >= 0; i--){
    R2[i] = RsumV[i] - 2 * (C - X[i]);
  }

  for (int i = 0; i < N + 2; i++){
    L2[i] = sumV[i] - X[i];
    if (i > 0){
      L2[i] = max(L2[i - 1], L2[i]);
    }
  }
  
  for (int i = N + 1; i >= 1; i--){
    ans = max(ans, R2[i] + L2[i - 1]);
  }
  
  cout << ans << endl;
  

  return 0;
}
