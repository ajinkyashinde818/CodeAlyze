#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  
  vector<int> A(N);
  int count = 0;
  long sum = 0;

  for (int i = 0; i < N; i++) {
    int v ;
    cin >> v;
    if (v < 0) {
      count++;
    }
    A[i] = abs(v);
    sum += A[i];
  }

  sort(A.begin(), A.end());

  if (count % 2 != 0) {
    sum -= (2 * A[0]);
  }

  cout << sum << endl;
  
}
