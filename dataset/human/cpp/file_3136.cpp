#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll gcd(ll A, ll B) {
  if (A < B) {
    swap(A, B);
  }
  if (B == 0) {
    return A;
  }
  return gcd(B, A % B);
}

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  bool zero_in_A = false;
  int minus_count = 0;
  ll min_v = pow(10, 9) + 1;
  for (int i = 0; i < N; ++i) {
    cin >> A.at(i);
    if (A.at(i) == 0) {
      zero_in_A = true;
    } else {
      min_v = min(min_v, abs(A.at(i)));
    }
    
    if (A.at(i) < 0) {
      ++minus_count;
    }
  }
  
  ll result = 0;
  for (int i = 0; i < N; ++i) {
    result += abs(A.at(i));
  }
  if (!zero_in_A && minus_count % 2 == 1) {
    result -= min_v * 2;
  }
  cout << result << endl;
}
