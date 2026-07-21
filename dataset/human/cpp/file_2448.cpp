#include <iostream>
using namespace std;
typedef long long ll;

int main(void){
    ll n, a[100010];
    cin >> n;
    ll k = 0, sm = 0, mn = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += abs(a[i]);
        mn = min(mn, abs(a[i]));
        if (a[i] <= 0) k++;
    }
    
    if (k % 2 == 0) cout << sm << endl;
    else cout << sm - 2*mn << endl;
    
}
