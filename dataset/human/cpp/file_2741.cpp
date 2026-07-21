#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> A(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> A[i + 1];
    }

    const long long INF = 1LL << 60;
    vector<long long> dp(2, -INF);
    dp[0] = 0;
    auto ndp = dp;
    for (int i = 1; i <= n; ++i) {
        fill(ndp.begin(), ndp.end(), -INF);
        
        for (int j = 0; j < 2; ++j) {
            if (dp[j] <= -INF) {
                continue;
            }
            
            for (int k = 0; k < 2; ++k) {
                long long v = A[i];
                if ((j ^ k)) {
                    v = -v;
                }
                ndp[k] = max(ndp[k], dp[j] + v);
            }
        }

        swap(ndp, dp);
    }

    cout << dp[0] << "\n";

    return 0;
}
