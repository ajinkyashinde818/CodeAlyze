#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

typedef long long ll;


int main(void) {
    
    
    ll N;
    ll m = LLONG_MAX;
    ll max = 0;
    vector<ll> a;
    
    cin >> N;
    
    for (ll i = 0; i < N; ++i) {
        
        ll tmp; cin >> tmp;
        
        max += tmp;
        
        a.push_back(max);
        
    }
    
    for (ll i = 0; i < N - 1; ++i) {
        
        m = min(m, abs(a[i] - (max - a[i])));
        
    }
    
    
    cout << m << endl;
    
    
    return 0;
    
}
