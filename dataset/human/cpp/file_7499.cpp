#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a;
  for (int i=0; i<n; i++) {
    long long tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  vector<long long> sum;
  long long tmp=0;
  for (int i=0; i<n; i++) {
    tmp += a[i];
    sum.push_back(tmp);
  }

  long long min = 2000000000;
  for (int i=0; i<(int)sum.size()-1; i++) {
    long long p1 = sum[i];
    long long p2 = sum[sum.size()-1]-p1;
    if (abs(p1-p2) < min) {
      min = abs(p1-p2);
    }
  }

  cout << min << endl;

  return 0;
}
