#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int num_min = 0;
  long min_num = 10e9;
  long sum=0;
  for (int i = 0; i < n; i++) {
    int aa;
    cin >> aa;
    if (aa<0) {
      num_min++;
    }
    int aaa  = abs(aa);
    if (min_num > aaa) {
      min_num = aaa;
    }
    sum += aaa;
  }
  if (num_min%2==0) {
    cout << sum << endl;
  } else {
    cout << sum - min_num*2 << endl;
  }
  return 0;
}
