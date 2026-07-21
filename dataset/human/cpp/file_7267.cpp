#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const int MOD = 1000000007;
using namespace std;

int main(){
    int n; cin >> n;
    ll sum = 0, ans = 1000000000000000000LL, partSum = 0;
    vector<ll> a(n);
    REP(i, n){
        cin >> a[i];
        sum += a[i];
    }
    REP(i, n){
        partSum += a[i];
        if(i<n-1) ans = min (ans, abs(sum-2*partSum));
    }
    cout << ans << "\n";
    return 0;
}
