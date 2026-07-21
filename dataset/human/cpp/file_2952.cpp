#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
#include<utility>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0, cnt = 0, mi = LINF;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += abs(a[i]);
        mi = min(mi, abs(a[i]));
        cnt += (a[i] < 0 ? 1 : 0);
    }
    ll ans = sum;
    if(cnt % 2 == 1){
        ans -= mi * 2;
    }
    cout << ans << endl;
    return 0;
}
