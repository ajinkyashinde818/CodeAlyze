#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
ll a[2 * 100010];
ll b[2 * 100010];
const ll INF = 1 << 29;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    ll sum = 0;
    for(int i = 0; i < N; ++i){
        cin >> a[i];
        sum += a[i];
    }
    
    b[0] = a[0];
    for(int i = 1; i < N; ++i){
        b[i] = a[i] + b[i - 1];
    }

    ll ans = abs(b[0] - (sum - b[0]));
    for(int i = 1; i < N - 1; ++i){
        ans = min(ans, abs(b[i] - (sum - b[i])));
    }
    cout << ans << endl;

    return 0;
}
