#include <iostream>

using namespace std;

long long nums[100000];
long long n;
long long memo[100000];
bool memoed[100000];
long long memo_r[100000];
bool memoed_r[100000];

long long dp(unsigned long long idx, bool reversed) {
  if( (reversed && memoed_r[idx]) || (!reversed && memoed[idx]) )
    return (reversed ? memo_r[idx] : memo[idx]);
  if (idx == 0)
    return reversed ? - 1 * 100000 : 0;
  long long num = nums[idx - 1];
  long long res;
  if (reversed) {
    res = max(dp(idx - 1, false) - num, dp(idx - 1, true) + num);
    memo_r[idx] = res;
    memoed_r[idx] = true;
  }
  else {
    res = max(dp(idx - 1, false) + num, dp(idx - 1, true) - num);
    memo[idx] = res;
    memoed[idx] = true;
  }
    return res;
}

int main(void) {
    cin >> n;
    // cout << n << endl;
    for (int i = 0; i < n; i++) {
        // cout << i << endl;
        cin >> nums[i];
    }
    cout << dp(n, false) << endl;
}
