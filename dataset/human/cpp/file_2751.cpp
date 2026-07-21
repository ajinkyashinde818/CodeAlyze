#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  int negative = 0;
  for (int i = 0; i < N; i++)
    if (A[i] < 0)
      negative++, A[i] *= -1;

  sort(A.begin(), A.end());

  long long ans = 0;
  if (negative % 2 == 0)
    for (int i = 0; i < N; i++)
      ans += A[i];
  else
    for (int i = 0; i < N; i++)
      if (i == 0)
        ans += A[i] * -1;
      else
        ans += A[i];

  cout << ans << endl;
}
