#include<iostream>
using namespace std;
inline int min(int a, int b) { return a < b ? a : b; }
inline int abs(int n) { return n < 0 ? -n : n; }
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  int mi = 2e9;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mi = min(mi, abs(t));
    sum += abs(t);
    cnt += (t <= 0);
  }
  cout << (cnt % 2 ? sum - 2 * mi : sum) << endl;
}
