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
    string s;
    cin >> s;

    int N = s.length();
    assert(n * 2 == N);

    const long long MOD = 1000000007LL;
    long long res = 1;
    if (s[0] != 'B') {
        res = 0;
    } else {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            int c = s[i] == 'B' ? 1 : 0;
            if (cnt == 0) {
                if (c == 0) {
                    res = 0;
                    break;
                }
                ++cnt;
                continue;
            }
            if ((c ^ (cnt & 1)) & 1) {
                ++cnt;
            } else {
                (res *= cnt) %= MOD;
                --cnt;
            }
        }
        if (cnt != 0) {
            res = 0;
        }

        for (int i = 0; i < n; ++i) {
            (res *= (i + 1)) %= MOD;
        }
    }

    cout << res << '\n';

    return 0;
}
