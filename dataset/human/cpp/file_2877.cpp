#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
using namespace std;

int main()
{
  int64_t N, ans = 0, rcnt = 0, minnum = 10e+7, a;
  cin >> N;

  for (int64_t i = 0; i < N; i++)
  {
    cin >> a;
    ans += abs(a);
    minnum = min(minnum, abs(a));
    if (a < 0)
    {
      rcnt++;
    }
  }

  if (rcnt % 2 != 0)
  {
    ans -= minnum * 2;
  }

  cout << ans << endl;
}
