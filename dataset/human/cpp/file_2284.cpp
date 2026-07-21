#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <functional>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);

    int cnt = 0;
    ll sum = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] < 0)cnt++;
        sum += abs(a[i]);
    }

    if(cnt % 2 == 0)cout << sum << endl;
    else{
        ll m = -1e10;
        ll p = 1e10;

        for(int i = 0;i < n;i++){
            if(a[i] < 0)m = max(m,a[i]);
            else p = min(p,a[i]);
        }

        cout << max(sum+2*m,sum-2*p) << endl;
    }
}
