#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <functional>
#include <stdio.h>
using namespace std;

typedef long long ll;

ll n;

int main(int argc, const char * argv[]){
    cin>>n;
    vector<ll> vec(n, 0);
    ll s = 0;
    ll res = numeric_limits<ll>::max();
    for(int i = 0; i < n; ++i){
        cin>>vec[i];
        s += vec[i];
    }
    ll t = 0;
    for(int i = 0; i < n; ++i){
        t += vec[i];
        if(i + 1 < n)res = min(res, abs(s - 2 * t));
    }
    cout<<res<<endl;
    return 0;
}
