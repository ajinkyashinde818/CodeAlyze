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
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 234567;
int a[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    int cnt = 0, mn = (int)1e9;
    LL sum = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) {
           a[i] *= -1;
           cnt++;
        }
        sum += a[i];
        mn = min(mn, a[i]);
    }
    if (cnt % 2) printf("%lld\n", sum - 2 * mn);
    else printf("%lld\n", sum);
    return 0;
}
