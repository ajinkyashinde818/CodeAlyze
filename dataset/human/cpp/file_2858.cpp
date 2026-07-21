#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <set>

using namespace std;
using llong = long long;
const int MOD=1000000007;

int main(int argc, char**argv){
    llong n;
    cin >> n;
    vector<llong> a(n);
    llong n_neg = 0;
    llong min_val = 1LL << 60;
    llong sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < 0) n_neg++;
        min_val = min(min_val, abs(a[i]));
        sum += abs(a[i]);
    }

    if (n_neg % 2 == 0) cout << sum << endl;
    else cout << sum - 2*min_val << endl;

    return 0;
}
