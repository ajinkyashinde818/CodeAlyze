#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
#include <iomanip>
#include <queue>
#include <cmath>
#include <math.h>
#include <string>
#include <sstream>
#include <set>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
using pll = pair<long long, long long>;
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {

    // 標準入力が早くなる。Cスタイルの入出力とC++スタイルの入出力を混合させてはならない。
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, R;
    cin >> N >> R;

    int rate = 0;
    if (N >= 10) {
        rate = R;
    }
    else {
        rate = 100 * (10 - N) + R;
    }
    cout << rate << endl;

	return 0;
}
