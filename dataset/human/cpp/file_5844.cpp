#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  long long C;
  cin >> C;
  vector<long long> x(N);
  vector<int> v(N);
  for (int i = 0; i < N; i++){
    cin >> x[i] >> v[i];
  }
  vector<long long> L1(N + 1, 0);
  L1[1] = v[0] - x[0];
  for (int i = 1; i < N; i++){
    L1[i + 1] = L1[i] + (v[i] - (x[i] - x[i - 1]));
  }
  vector<long long> L2(N + 1, 0);
  for (int i = 1; i <= N; i++){
    L2[i] = L1[i] - x[i - 1];
  }
  vector<long long> R1(N + 1, 0);
  R1[N - 1] = v[N - 1] - (C - x[N - 1]);
  for (int i = N - 2; i >= 0; i--){
    R1[i] = R1[i + 1] + v[i] - (x[i + 1] - x[i]);
  }
  vector<long long> R2(N + 1, 0);
  for (int i = 0; i < N; i++){
    R2[i] = R1[i] - (C - x[i]);
  }
  for (int i = 1; i <= N; i++){
    L1[i] = max(L1[i], L1[i - 1]);
    L2[i] = max(L2[i], L2[i - 1]);
  }
  for (int i = N - 1; i >= 0; i--){
    R1[i] = max(R1[i], R1[i + 1]);
    R2[i] = max(R2[i], R2[i + 1]);
  }
  long long ans = 0;
  for (int i = 0; i <= N; i++){
    ans = max(ans, L1[i] + R2[i]);
    ans = max(ans, L2[i] + R1[i]);
  }
  cout << ans << endl;
}
