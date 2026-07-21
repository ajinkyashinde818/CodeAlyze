#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-11;

vector<int> ans[2000];

int main() {
    ll n;
    cin >> n;
    ll k = -1;
    bool ok = false;
    for (int i = 0; i * (i - 1) / 2 <= 100005; i++) {
        if (i * (i - 1) / 2 == n) {
            k = i;
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << k << endl;
        int tmp = 1;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                ans[i].push_back(tmp);
                ans[j].push_back(tmp);
                tmp++;
            }
        }
        for (int i = 0; i < k; i++) {
            string s = "";
            int len = ans[i].size();
            s += to_string(len);
            for (int j = 0; j < len; j++) {
                s += " ";
                s += to_string(ans[i][j]);
            }
            cout << s << endl;
        }
    }
}
