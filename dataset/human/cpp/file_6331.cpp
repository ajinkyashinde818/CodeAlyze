#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <numeric>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;

int main() {

    
    ll n;
    string s;
    cin >> n >> s;
    
    if (s[0] == 'W' || s[2 * n - 1] == 'W')
    {
        cout << 0 << endl;
        return 0;
    }
    
    vector<ll> c(2 * n);
    vector<ll> l, r;
    c[2 * n - 1] = 1;
    l.push_back(0);
    r.push_back(2 * n - 1);
    for (int i = 1; i < 2 * n - 1; ++i)
    {
        if (s[i] == s[i - 1])
        {
            c[i] = !c[i - 1];
        }
        else
        {
            c[i] = c[i - 1];
        }
        if (c[i])
        {
            r.push_back(i);
        }
        else
        {
            l.push_back(i);
        }
    }
    if (l.size() != r.size())
    {
        cout << 0 << endl;
        return 0;
    }
    if (s[2 * n - 1] == s[2 * n - 2])
    {
        if (c[2 * n - 1] != !c[2 * n - 2])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    else
    {
        if (c[2 * n - 1] != c[2 * n - 2])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    
    ll ret = 1;
    for (int i = 0; i < n; ++i)
    {
        ll pos = lower_bound(l.begin(), l.end(), r[i]) - l.begin();
        ret *= (pos - i);
        ret %= mod;
    }
    for (int i = 0; i < n; ++i)
    {
        ret *= (i + 1);
        ret %= mod;
        
    }
    
    cout << ret << endl;
    
    return 0;
}
