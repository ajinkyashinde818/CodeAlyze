#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    ll A[N];
    REP(i, N) cin >> A[i];

    ll dpt[N], dpf[N];
    dpt[0] = (A[0] + A[1]) * -1;
    dpf[0] = (A[0] + A[1]);
    FOR(i, 1, N - 1) {
        dpt[i] = max(dpt[i - 1] - (-1 * A[i]) + A[i] + -1 * A[i + 1],
                     dpf[i - 1] - A[i] + -1 * A[i] + -1 * A[i + 1]);
        dpf[i] = max(dpt[i - 1] - (-1 * A[i]) + -1 * A[i] + A[i + 1],
                     dpf[i - 1] - A[i] + A[i] + A[i + 1]);
    }
    cout << max(dpt[N - 2], dpf[N - 2]) << endl;

    return 0;
}
