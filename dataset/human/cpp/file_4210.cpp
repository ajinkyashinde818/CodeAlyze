#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ans = n;
    ll sum = 1;
    ll cnt = 0;
    for(ll i = 3;; i *= 3){
        if(sum*2+i-1 > n)   break;
        cnt++;
        ll tmp = cnt*2-1;
        ll res = n-sum-sum+1;
        ll cp = i;
        while(res){
            tmp += res/cp;
            res -= res/cp*cp;
            cp /= 3;
        }
        ans = min(ans, tmp);
        sum += i;
    }
    cout << ans << endl;
    return 0;
}
