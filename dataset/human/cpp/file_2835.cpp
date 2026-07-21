#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> as;
  ll tmp;
  ll negativeCount = 0;
  ll zeroCount = 0;
  for(int i = 0; i < N; ++i) {
    cin >> tmp;
    if(tmp < 0) {
      negativeCount++;
      tmp = -tmp;
    } else if(tmp == 0) {
      zeroCount++;
    }
    as.push_back(tmp);
  }
  sort(as.begin(), as.end());

  ll sum = accumulate(as.begin(), as.end(), 0LL);
  if(zeroCount == 0 && negativeCount % 2 == 1) {
    sum -= as[0] * 2;
  }
  cout << sum << endl;
  return 0;
}
