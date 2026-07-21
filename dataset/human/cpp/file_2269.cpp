#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll inf = INT64_MAX / 4;
constexpr ll mod = 1000000007;

ll dp[100001][2];

int main() {
    int n, a[100000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[1][0] = a[0];
    dp[1][1] = -a[0];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max((dp[i - 1][0] + a[i - 1]), (dp[i - 1][1] - a[i - 1]));
        dp[i][1] = max((dp[i - 1][0] - a[i - 1]), (dp[i - 1][1] + a[i - 1]));
    }
    cout << dp[n][0] << endl;
}
