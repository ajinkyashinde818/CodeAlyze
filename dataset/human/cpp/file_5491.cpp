#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N, R; cin >> N >> R;
    if (N >= 10) cout << R << endl;
    else cout << R + 100 * (10 - N) << endl;
}
