#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <random>
#include <complex>

#define _1 first
#define _2 second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define reset(x, y) memset(x, y, sizeof(x))
#define BUG(x) cerr << #x << " = " << (x) << endl
#define BUGP(x) cout << #x << " = " << (x)._1 << ", " << (x)._2 << endl
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

const int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dc[] = {0, -1, 0, 1, -1, 1, -1, 1};
// Head

const int N = 112345;
const int MOD = int(1e9) + 7;

LL fac[N];
int n;
string s;

int main() {
    cin >> n;

    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;

    cin >> s;
    LL ans = 1;
    LL cur = 0;

    for (int i = 0; i < s.length(); i++) {
        int tmp = 0;
        if (s[i] == 'B') tmp = 1;

        if ((tmp + cur) % 2 == 1) ++cur;
        else {
            //cout << ans << ' ' << i << endl;
            ans = ans * cur % MOD;
            --cur;
        }
    }

    if (cur) {
        cout << 0 << '\n';
        return 0;
    }
    //cout << ans << endl;

    cout << ans * fac[n] % MOD << '\n';
    return 0;
}
