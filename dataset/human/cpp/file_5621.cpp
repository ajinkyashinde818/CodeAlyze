#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
int int_max = 2147483647;
int max_n = 1e5;
using mat2d_t = std::vector<std::vector<int64_t>>;



int main(int argc, char **argv) {
    int n, r;
    cin >> n >> r;
    int ans;
    if (n >= 10) ans = r;
    else ans = 100*(10-n) + r;

    cout << ans << endl;

    return 0;
}
