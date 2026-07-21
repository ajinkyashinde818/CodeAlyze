#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <functional>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279
#endif

#define int long long

#define mp make_pair
#define mt make_tuple
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define get0 get<0>
#define get1 get<1>
#define get2 get<2>
#define get3 get<3>

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef tuple<long long, long long, long long> tlll;
typedef tuple<int, int, int> tiii;
typedef tuple<int, int, int, int> tiiii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MOD = 1e9 + 7;



int32_t main()
{
#ifdef chikibambony
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> b[j];
    }
    reverse(all(b));
    int c = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            c = a[i];
            break;
        }
    }
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == c && b[i] == c) {
            l = i;
            break;
        }
    }
    int r = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == c && b[i] == c) {
            r = i;
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] != c && b[i] != c && l <= r) {
            swap(b[i], b[l]);
            ++l;
        }
    }

    if (l <= r) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";

    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
        //assert(b[i] != a[i]);
    }
    cout << "\n";

    return 0;
}
