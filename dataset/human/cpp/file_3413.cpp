#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int A[200010];

int main() {
  int N; cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N-1; i++) {
    if (A[i] < 0) {
      A[i] *= -1; A[i+1] *= -1;
    }
  }
  if (A[N-1] > 0) {
    long sum = 0;
    for (int i = 0; i < N; i++) sum += A[i];
    cout << sum << endl;
  }
  else if (find(A, A+N, 0) != A+N) {
    long sum = 0;
    for (int i = 0; i < N; i++) sum += abs(A[i]);
    cout << sum << endl;
  }
  else {
    for (int i = 0; i < N; i++) A[i] = abs(A[i]);
    long sum = 0;
    for (int i = 0; i < N; i++) sum += A[i];
    sum -= 2 * *min_element(A, A+N);
    cout << sum << endl;
  }
}
