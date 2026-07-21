#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
    }

    ll s = 0;
    for(int i = 0; i < n; ++i){
        s += a.at(i);
    }

    ll snuke = a.at(0);
    ll ans = abs((s - snuke) - snuke);
    for(int i = 1; i < n - 1; ++i){
        snuke += a.at(i);
        ans = min(ans, abs((s - snuke) - snuke));
    }
    cout << ans << endl;
    return 0;
}
