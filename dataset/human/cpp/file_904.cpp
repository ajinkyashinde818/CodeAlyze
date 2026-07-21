// {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// }}}

using ll = long long;

int R, G, B, N;

int main() {
    cin >> R >> G >> B >> N;
    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            int q = N - R * i - G * j;
            if (q >= 0 && q % B == 0) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
