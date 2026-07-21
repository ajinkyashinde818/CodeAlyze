#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <utility>
#include <list>
#include <climits>
#include <bitset>
#include <numeric>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); i++)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define ll long long int

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    in_arr(ll, a, n);
    if(n == 2){
        cout << abs(a[0] - a[1]) << endl;
        return 0;
    }
    ll s = 0, ar = 0, ans = LLONG_MAX;
    for(int i = 0; i < n; ++i){
        ar += a[i];
    }
    for(int i = 0; i < n - 1; ++i){
        s += a[i];
        ar -= a[i];
        ans = min(ans, abs(s - ar));
    }
    cout << ans << endl;
    return 0;
}
