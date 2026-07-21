#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <bitset>
   
using namespace std;
   
 
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define rforeach(it, c) for (__typeof__((c).rbegin()) it=(c).rbegin(); it != (c).rend(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CL(arr, val) memset(arr, val, sizeof(arr))
#define COPY(dest, src) memcpy(dest, src, sizeof(dest))
#define ten(n) ((long long)(1e##n))
#define bin(n) (1ull << (n))
#define erep(i, n) for (int i = 0; i <= (int)(n); ++i)
#define revrep(i, n) for (int i = (n); i >= 0; --i)
#define pb push_back

template <class T> void chmax(T& a, const T& b) { a = max(a, b); }
template <class T> void chmin(T& a, const T& b) { a = min(a, b); }

template <class T> T round_up(T a, T b) { return (a + b - 1) / b; }

template <class T> void uniq(vector<T>& c) { sort(c.begin(), c.end()); c.erase(unique(c.begin(), c.end()), c.end()); }
 
template <class T> string to_s(const T& a) { ostringstream os; os << a; return os.str(); }
template <class T> T to_T(const string& s) { istringstream is(s); T res; is >> res; return res; }
  
template <class T, class U> ostream& operator<<(ostream& os, pair<T, U>& p) { os << "( " << p.first << ", " << p.second << " )"; return os; }
  
template <class T> void print(T a, int n, const string& deli = " ", int br = 1) { for (int i = 0; i < n; ++i) { cout << a[i]; if (i + 1 != n) cout << deli; } while (br--) cout << endl; }
template <class T> void print(const T& c, const string& deli = " ", int br = 1) { foreach (it, c) { cout << *it; if (++it != c.end()) cout << deli;--it; } while (br--) cout << endl; }
template <class T> void print2d(T a, int w, int h, int width = -1, int br = 1) { for (int i = 0; i < h; ++i) { for (int j = 0; j < w; ++j) {    if (width != -1) cout.width(width); cout << a[i][j] << ' '; } cout << endl; } while (br--) cout << endl; }
   
template <class T> void input(T& a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }
template <class T> void input(T* a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }

void fix_pre(int n) { cout.setf(ios::fixed, ios::floatfield); cout.precision(10); }
void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }
#define trace(x) (cout << #x << ": " << (x) << endl)
 
bool in_rect(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }


typedef long long ll;
typedef pair<int, int> pint;
 
// y(v): v>^<  y(^): ^>v<
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

const double PI = acos(-1.0);

#define F first
#define S second


ll inverse_base(const string& s, int base)
{
    static const char* digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ll res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        char c = isdigit(s[i]) ? s[i] : toupper(s[i]);
        int d = strchr(digits, c) - digits;
        assert(0 <= d && d < 36);
        res = (res * base) + d;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        ll num = inverse_base(s, 16);
        ll fra_part = num & (bin(7) - 1);
        num >>= 7;
        int int_part = num & (bin(24) - 1);
        num >>= 24;
        int sign_part = num;

        string res;
        if (sign_part)
            res += '-';
        res += to_s(int_part) + '.';

        fra_part |= bin(7);
        fra_part *= ten(10);
        fra_part >>= 7;

        vector<int> f;
        f.pb(0);
        while (fra_part > 0)
        {
            f.pb(fra_part % 10);
            fra_part /= 10;
        }
        f.pop_back();
        reverse(all(f));
        while (f.size() > 1 && f.back() == 0)
            f.pop_back();
        rep(i, f.size())
            res += '0' + f[i];

        cout << res << endl;
    }
}
