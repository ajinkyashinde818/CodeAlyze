#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <list>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> A;
  ll sum = 0;
  int cnt_minus_num = 0;
  int min_absolute_value = 1e9;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a < 0) {
      cnt_minus_num++;
      sum -= a;
      min_absolute_value = min(min_absolute_value, -a);
    }
    else {
      sum += a;
      min_absolute_value = min(min_absolute_value, a);
    }
  }
  if (cnt_minus_num % 2 != 0) {
    sum -= 2 * min_absolute_value; 
  }
  
  cout << sum;
  return 0;
}
