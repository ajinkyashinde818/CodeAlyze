#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n;
    cin >> n;
    
    vector<ll> a(n), a_abs(n);
    ll res = 0, c = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a_abs[i] = abs(a[i]);
        res += a_abs[i];
        if (a[i] < 0) c++;
    }
    

    if (c % 2 == 1) {
        res -= 2 * *min_element(a_abs.begin(), a_abs.end());
    }
  
    cout << res << endl;
    
}
