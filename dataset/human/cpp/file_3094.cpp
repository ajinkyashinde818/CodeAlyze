#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  int ope = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) < 0) {
      ope++;
    }
  }

  for (int i = 0; i < N; i++) {
    if (A.at(i) < 0) {
      A.at(i) *= -1;
    }
  }
  sort(A.begin(), A.end());

  long long sum = 0;
  if (ope % 2 == 0) {
    for (int i = 0; i < N; i++) {
      sum += A.at(i);
    }
  }
  else {
    sum -= A.at(0);
    for (int i = 1; i < N; i++) {
      sum += A.at(i);
    }
  }

  cout << sum << endl;
}
