#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll INF = 9223372036854775807;
int main(void){
    int n;
    cin >> n;
    vector<ll> a(n),rui(n+1);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        rui[i+1] = rui[i] + a[i];
    }
    ll ans = INF;
    for(int i = 0;i < n-1;i++){
        ans = min(ans,abs(rui[n]-2*rui[i+1]));
    }
    cout << ans << endl;
    return 0;
}
