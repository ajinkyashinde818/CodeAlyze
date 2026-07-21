#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    using ll = long long;
    
    int n;
    cin >> n;
    
    vector<ll> a(n);
    int m_c = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
        if (a[i] < 0) {
            m_c++;
            a[i] = -a[i];
        }
    }
    
    sort(a.begin(), a.end());
    
    ll ans = 0;
    
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    
    if (m_c % 2 == 1) {
        ans -= a[0] * 2;
    }
    
    cout << ans << endl;
}
