#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;

int N;
long long a[MAX_N + 1];

int main() {
  cin >> N;
  long long sum = 0;
  long long x = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long ans = 100000000000000;
  for (int i = 0; i < N - 1; i++) {
    x += a[i];
    ans = min(ans, abs(sum - 2 * x));
  }
  cout << ans << endl;
}
