#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;
typedef long long ll;

int main(){

    int n; cin >> n;

    ll a[n];

    int cntNegative = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] < 0) cntNegative++;
    }

    ll ans = 0;
    if(cntNegative % 2 == 0){
        for(int i=0; i<n; i++){
            ans += abs(a[i]);
        }
    }
    else{
        ll vmin = 1e9;
        for(int i=0; i<n; i++){
            ans += abs(a[i]);
            vmin = min(vmin, abs(a[i]));
        }

        ans -= 2*vmin;
    }

    cout << ans;

    return 0;
}
