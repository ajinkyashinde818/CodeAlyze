#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long llong;
typedef pair<llong, llong> pii;

int n;
llong C;
llong X[100001];
int V[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> C;
    for (int i = 1; i <= n; ++i) cin >> X[i] >> V[i];
    priority_queue<pii> pq1, pq2;
    pq1.emplace(0, n + 1);
    pq2.emplace(0, n + 1);
    llong sum = 0;
    for (int i = n; i; --i) {
        sum += V[i];
        pq1.emplace(sum - (C - X[i]), i);
        pq2.emplace(sum - (C - X[i] << 1), i);
    }
    sum = 0;
    llong mx1 = 0, mx2 = 0;
    llong ans = 0;
    for (int i = 0; i <= n; ++i) {
        sum += V[i];
        mx1 = max(mx1, sum - X[i]);
        mx2 = max(mx2, sum - (X[i] << 1));
        while (pq1.top().second <= i) pq1.pop();
        while (pq2.top().second <= i) pq2.pop();
        ans = max(ans, max(pq1.top().first + mx2, pq2.top().first + mx1));
    }
    printf("%lld\n", ans);
    return 0;
}
