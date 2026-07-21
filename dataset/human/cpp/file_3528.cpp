#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

ll A[100000];

int main() {
    int n; cin >> n;
    bool r = 0;
    bool o = 0;
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
        if(A[i] < 0) r = !r;
        if(A[i] == 0) o = 1;
    }
    
    ll mn = 0;
    if(r && o == 0) mn = accumulate(A, A + n, 1e9, [](ll x, ll y) -> ll { return (abs(x) < abs(y) ? x : y); });
    
    cout << accumulate(A, A + n, 0LL, [](ll x, ll y) -> ll{ return abs(x) + abs(y); }) - 2 * abs(mn);
    return 0;
}
