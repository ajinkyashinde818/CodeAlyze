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
    long long C;
    cin >> n >> C;

    vector<long long> X(n + 1, 0);
    vector<long long> V(n + 1, 0);
    for (int i = 0; i < n;++i) {
        cin >> X[i + 1] >> V[i + 1];
    }
    ++n;
    
    vector<long long> A(n * 2 + 1, 0);
    vector<long long> B(n * 2, 0);
    for (int i = 0; i < 2 * n; ++i) {
        A[i + 1] = A[i] + V[i % n];
    }
    for (int i = 0; i < 2 * n; ++i) {
        B[i] = (i >= n ? 1 : 0) * C + X[i % n];
    }

    const long long INF = 1LL << 60;
    long long res = 0;

    for (int i = 0; i <= n; ++i) {
        res = max(res, A[i + 1] - A[0] - (B[i] - B[0]));
        res = max(res, A[n + 1] - A[i] - (B[n] - B[i]));
        // cout << i << " " << res << endl;
    }

    deque<pair<long long,int>> que1;
    deque<pair<long long,int>> que2;

    auto push = [&](deque<pair<long long, int>>& que, long long val, int pos) -> long long {
        while (!que.empty()) {
            int l = que.front().second;
            if (l + n <= pos) {
                que.pop_front();
            } else {
                break;
            }
        }

        while (!que.empty()) {
            if (que.back().first <= val) {
                que.pop_back();
            } else {
                break;
            }
        }

        long long res = 0;
        if (!que.empty()) {
            res = max(res, que.front().first);
        }
        que.emplace_back(val, pos);
        return res;
    };

    for (int i = 0; i <= n; ++i) {
        push(que1, A[n + 1] - A[i] - 2 * (B[n] - B[i]), i);
        push(que2, A[n + 1] - A[i] - (B[n] - B[i]), i);
        // cout << i << " " << A[n + 1] - A[i] << " " << A[n + 1] - A[i] - 2 * (B[n] - B[i]) <<  "  " << A[n + 1] - A[i] - (B[n] - B[i]) << endl;
    }

    for (int i = 1; i < n; ++i) {
        {
            long long ans = push(que1, -INF, i + n);
            ans += A[i + n + 1] - A[n] - (B[i + n] - B[n]);
            res = max(res, ans);
        }
        {
            long long ans = push(que2, -INF, i + n);
            // cout << "   " << ans << endl;
            ans += A[i + n + 1] - A[n] - 2 * (B[i + n] - B[n]);
            res = max(res, ans);
            // cout << i << " " << ans << endl;
        }
    }

    cout << res << '\n';
    return 0;
}
