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

int main() {

    
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll c = 0;
    ll ret = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            c++;
            ret -= a[i];
            a[i] = -a[i];
        }
        else
        {
            ret += a[i];
        }
    }
    if (c % 2)
    {
        sort(a.begin(), a.end());
        ret -= (2ll * a[0]);
    }
    
    cout << ret << endl;
    
    return 0;
}
