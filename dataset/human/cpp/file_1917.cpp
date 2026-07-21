#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>
#include <iomanip>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        u32 x;
        scanf("%x", &x);
        cout << setprecision(100) << (x&(1u << 31) ? "-" : "") << ldexp(x&((1u << 31)-1), -7) << (!(x&((1u << 7)-1)) ? ".0" : "") << "\n";
    }
    return 0;
}
