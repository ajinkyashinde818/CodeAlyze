#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 123456;
LL x[MAXN], v[MAXN];
LL premax[MAXN], sufmax[MAXN], presum[MAXN], sufsum[MAXN];

int main() {
    LL N, C;
    while (~scanf("%lld %lld", &N, &C)) {
          for (int i = 1; i <= N; i++) {
              scanf("%lld %lld", &x[i], &v[i]);
          }
          sufmax[N + 1] = sufsum[N + 1] = 0;
          for (int i = N; i >= 1; i--) {
              sufsum[i] = sufsum[i + 1] + v[i];
              sufmax[i] = max(sufmax[i + 1], sufsum[i] - (C - x[i]));
          }
          premax[0] = presum[0] = 0;
          for (int i = 1; i <= N; i++) {
              presum[i] = presum[i - 1] + v[i];
              premax[i] = max(premax[i - 1], presum[i] - x[i]);
          }
          LL ans = 0;
          for (int i = 1; i <= N; i++) {
              LL tmp_ans = max(presum[i] - x[i], presum[i] - 2 * x[i] + sufmax[i + 1]);
              // printf("i = %d pre = %lld\n", i, tmp_ans);
              ans = max(ans, tmp_ans);
          }
          for (int i = N; i >= 1; i--) {
              LL dis = (C - x[i]);
              LL tmp_ans = max(sufsum[i] - dis, sufsum[i] - 2 * dis + premax[i - 1]);
              // printf("i = %d sufsum = %lld dis = %lld premax = %lld\n", i, sufsum[i], dis, premax[i - 1]);
              // printf("i = %d suf = %lld\n", i, tmp_ans);
              ans = max(ans, tmp_ans);
          }
          printf("%lld\n", ans);
    }
    return 0;
}
