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
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 123456;
const LL MOD = (LL)1e9 + 7;
char s[MAXN];
int cnt[26];

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", s);
    for (int i = N - 1; i >= 0; i--) {
        int cur = s[i] - 'a';
        cnt[cur]++;
    }
    LL ans = 1;
    for (int i = 0; i < 26; i++) {
        ans = (ans * (cnt[i] + 1)) % MOD;
    }
    printf("%lld\n", ans - 1);
    return 0;
}
