#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int64_t deff = 2000000000000000, sum = 0, temp = 0;
  cin >> N;
  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
  }
  
  for (int i = 0; i < N-1; i++) {
    temp += A.at(i);
    deff = min(deff, abs(sum - temp * 2));
  }
  cout << deff << endl;
}
