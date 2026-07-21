#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::min;
using std::max;
using std::fill;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define int long long

const long long MOD = 1e9 + 7;

string s;
int n;
vector<char> c;
int lefter_open[500000];
int lefter_close[500000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    int counter = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (counter % 2 == 0 && s[i] == 'B')
        {
            counter++;
            c.push_back('(');
        } else
        if (counter % 2 == 1 && s[i] == 'B')
        {
            counter--;
            c.push_back(')');
        } else
        if (counter % 2 == 0 && s[i] == 'W')
        {
            if (counter == 0)
            {
                cout << 0;
                return 0;
            }
            counter--;
            c.push_back(')');
        } else
        if (counter % 2 == 1 && s[i] == 'W')
        {
            counter++;
            c.push_back('(');
        }
    }
    if (counter != 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < 2 * n; i++)
    {
        if (i > 0) lefter_open[i] = lefter_open[i - 1];
        if (c[i] == '(') lefter_open[i]++;
    }
    for (int i = 0; i < 2 * n; i++)
    {
        if (i > 0) lefter_close[i] = lefter_close[i - 1];
        if (c[i] == ')') lefter_close[i]++;
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++) ans = i * ans % MOD;
    for (int i = 0; i < 2 * n; i++)
    {
        if (c[i] == ')')
        {
            ans = ans * (lefter_open[i] - lefter_close[i] + 1) % MOD;
        }
    }
    cout << ans;
}
