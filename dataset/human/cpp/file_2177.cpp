#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  long long min = 1999999999;
  int mai = 0;
  long long sum = 0;
  for (int i = 0; i < N; i ++) {
    int k;
    cin >> k;
    if (k < 0) {
      mai ++;
      k = -k;
    }
    sum += k;
    if (min > k) min = k;
  }
  if (mai % 2) cout << sum - min * 2 << endl;
  else cout << sum << endl;
}
