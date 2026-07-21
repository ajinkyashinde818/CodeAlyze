/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

signed main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ret = 0;
    for (int r = 0; r <= 3000; r++) {
        for (int g = 0; g <= 3000; g++) {
            int remain = N - G * g - R * r;
            if (remain >= 0 && remain % B == 0) ret++;
        }
    }
    cout <<ret << endl;
    return 0;
}
