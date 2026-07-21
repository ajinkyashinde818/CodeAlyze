#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <assert.h>
#include <utility>
#include <tuple>
#include <array>
#include <bitset>
#include <cstdlib>

using int64 = long long;

const int64 mod = 1e9 + 7;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::map<char, int> counter;
    for (char c : s) {
        counter[c]++;
    }

    int64 ans = 1;
    for (auto& mp : counter) {
        (ans *= mp.second + 1) %= mod;
    }
    ans--;

    std::cout << ans << std::endl;

    return 0;
}
