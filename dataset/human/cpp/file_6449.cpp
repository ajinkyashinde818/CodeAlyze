#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 123456;
const LL MOD = (LL)1e9 + 7;
char S[MAXN * 2];

void NO() {
     puts("0");
     exit(0);
}

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", S);
    LL ans = 1, cnt1 = 0;
    if (S[0] == 'W') NO();
    for (int i = 0; i < 2 * N; i++) {
        int cur = 0;
        if (S[i] == 'B') cur = 1;
        int type = cur ^ (cnt1 % 2);
        if (type) {
           if (cnt1 + 1 > (2 * N - i)) NO();
           cnt1++;
        } else {
           ans = (ans * cnt1) % MOD;
           cnt1--;
        }
        //printf("i = %d cnt1 = %lld\n", i, cnt1);
    }
    for (int i = 1; i <= N; i++) {
        ans = (ans * i) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
