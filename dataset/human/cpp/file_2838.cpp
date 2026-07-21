#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long int m;
  vector<long long int> a(N);
  priority_queue<long long int> q;
  for (int i = 0; i < N; i++) {
    long long int v;
    cin >> v;
    if (v < 0) {
      q.push(v);
      v *= -1;
    }
    if (i == 0) {
      m = v;
    }
    else {
      m = min(v, m);
    }
    a.at(i) = v;
  }
  long long int count = 0;
  for (int i = 0; i < N; i++) {
    count += a.at(i);
  }
  if (q.size() % 2 != 0) {
    count -= 2 * m;
  }
  printf("%lld\n", count);
}
