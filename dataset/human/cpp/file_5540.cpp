#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 1000000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n, r; cin >> n >> r;
    if (n >= 10) cout << r << endl;
    else cout << r + 100 * (10 - n) << endl;
    return 0;
}
