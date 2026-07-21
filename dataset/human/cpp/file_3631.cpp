#include<bits/stdc++.h>
using namespace std;

int main() {
  long long ans = 0;
  int N, c = 0;
  cin >> N;
  vector<long long> A(N), dp0(N+1), dp1(N+1);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  dp0.at(0) = 0;
  dp1.at(0) = -1000000000000000000;
  for(int i = 0; i < N; i++) {
    dp0.at(i+1) = max(dp0.at(i) + A.at(i), dp1.at(i) - A.at(i));
    dp1.at(i+1) = max(dp1.at(i) + A.at(i), dp0.at(i) - A.at(i));
  }
  cout << dp0.at(N);
}
