#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <set>
#include <climits>
#include <map>
#include <cmath>
#include <deque>
#include <numeric>

using namespace std;

long long x[100000];
long long v[100000];

long long cum_sum_v[100000];
long long max_profit[100000];
long long reverse_cum_sum_v[100000];
long long reverse_max_profit[100000];
int main(){
  int N;
  long long C;
  cin >> N >> C;
  for(int i = 0; i < N; i++){
    cin >> x[i] >> v[i];
  }

  cum_sum_v[0] = v[0];
  max_profit[N - 1] = cum_sum_v[0] - x[0];
  for(int i = 1; i < N; i++){
    cum_sum_v[i] = cum_sum_v[i - 1] + v[i];
    max_profit[i] = max(cum_sum_v[i] - x[i], max_profit[i - 1]);
  }

  reverse_cum_sum_v[N - 1] = v[N - 1];
  reverse_max_profit[N - 1] = reverse_cum_sum_v[N - 1] - (C - x[N - 1]);
  for(int i = N - 2; i >= 0; i--){
    reverse_cum_sum_v[i] = reverse_cum_sum_v[i + 1] + v[i];
    reverse_max_profit[i] = max(reverse_cum_sum_v[i] - (C - x[i]), reverse_max_profit[i + 1]);
  }

  long long ans = 0;


  //go right first
  //turn aroiund from start
  ans = max(ans, reverse_max_profit[0]);

  for(int i = 0; i < N - 1; i++){
    long long tmp_ans = cum_sum_v[i] - x[i];
    long long turn_around_profit = max((long long) 0, reverse_max_profit[i + 1] - x[i]);
    tmp_ans += turn_around_profit;
    ans = max(ans, tmp_ans);
  }
  //no turn around
  ans = max(ans, cum_sum_v[N - 1] - x[N - 1]);

  //go left first
  for(int i = N - 1; i > 0; i--){
    long long tmp_ans = reverse_cum_sum_v[i] - (C - x[i]);
    long long turn_around_profit = max((long long) 0, max_profit[i - 1] - (C  - x[i]));
    tmp_ans += turn_around_profit;
    ans = max(ans, tmp_ans);
  }

  cout << ans << endl;
  return 0;
}
