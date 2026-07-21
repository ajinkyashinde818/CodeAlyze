#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  long A[N];
  int cnt = 0;
  bool flag = false;
  long k = INT_MAX;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] < 0) {
      cnt++;
    }
    if(A[i] == 0){
      flag = true;
    }
    sum += abs(A[i]);
    k = min(k, abs(A[i]));
  }
  
  if (flag || cnt % 2 == 0) {
    cout << sum << "\n";
  } else {
    cout << sum - 2 * k << "\n";
  }
  return 0;
}
