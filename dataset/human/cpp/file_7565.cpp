#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N; cin >> N;
    vector<LLONG> as(N); for (auto &ai : as) cin >> ai;
    vector<LLONG> sums(N + 1, 0LL);
    for (int i = 1; i <= N; ++i)
    {
        sums[i] = sums[i - 1] + as[i - 1];
    }
    LLONG minDiff = 1e15;
    for (int i = 1; i < N; ++i)
    {
        LLONG x = sums[i] - sums[0];
        LLONG y = sums[N] - sums[i];
        minDiff = min(minDiff, llabs(x - y));
    }
    cout << minDiff << endl;
}
