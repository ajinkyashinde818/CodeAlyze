#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[N];
  int count = 0;
  int64_t sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(A[i] < 0) {
      A[i] *= -1;
      count++;
    }
    sum += A[i];
  }
  sort(A, A + N);
  if(count % 2 == 0) cout << sum << endl;
  else cout << sum - 2 * A[0] << endl;
}
