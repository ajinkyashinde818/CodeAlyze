#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int m = 1000000000;
  int mc = 0;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x < 0) mc += 1;
    sum += abs(x);
    m = min(m,abs(x));
  }
  cout << (mc % 2 == 0 ? sum : sum - 2*m) << endl;
}
