#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, count=0, sum=0, mini=LONG_MAX;
  cin >> N;
  vector<long> A(N);
  for (int i=0; i<N; i++) cin >> A.at(i);
  for (int i=0; i<N; i++) {
    if (A.at(i) < 0) count++;
  }
  for (int i=0; i<N; i++) {
    mini = min(mini, abs(A.at(i)));
    sum += abs(A.at(i));
  }
  if (count % 2 == 1) cout << sum - mini*2 << endl;
  else cout << sum << endl;
}
