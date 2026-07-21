#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  long long sumNum = 0;
  long long minNum = 10000000000;
  int minusCnt = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] < 0) {
      minusCnt++;
    }
    minNum = min(abs(A[i]), abs(minNum));
    sumNum += abs(A[i]);
  }

  if (minusCnt % 2 == 1) {
    sumNum -= minNum * 2;
  }

  cout << sumNum << endl;
}
