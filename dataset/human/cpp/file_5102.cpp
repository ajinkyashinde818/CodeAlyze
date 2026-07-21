#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <unordered_map>

#define DEBUG false
#define OJ_DEBUG

#define $(x) {if (DEBUG) {cout << __LINE__ << ": "; {x} cout << endl;}}
#define _(x) {cout << #x << " = " << x << " "; }
const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

typedef long long ll;
typedef std::pair<int, int> pii;
typedef unsigned long ul;

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, r;
    cin >> n >> r;
    if (n >= 10) {
        cout << r << '\n';
        return 0;
    }
    cout << r + 100 * (10 - n) << '\n';
    return 0;
}
