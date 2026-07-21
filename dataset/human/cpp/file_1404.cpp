#include <cstdio>
#include <iostream>
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
const int MAXN = 123456;
vector<int> ans[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    int tmp = n * 2;
    int k = sqrt(tmp);
    if (k * (k + 1) != tmp) return !printf("No\n");
    printf("Yes\n%d\n", k + 1);
    int cur = 1;
    for (int i = 1; i <= k + 1; i++) {
        printf("%d ", k);
        int cnt = 0;
        for (int j = 1; j < i; j++) {
            printf("%d ", ans[j].back());
            ans[j].pop_back();
            cnt++;
        }
        for (int j = 0; j < k - cnt; j++) {
            printf("%d ", cur);
            ans[i].push_back(cur++);
        }
        puts("");
    }

    return 0;
}
