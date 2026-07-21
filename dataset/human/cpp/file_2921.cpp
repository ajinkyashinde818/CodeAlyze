#include <iostream>
#include <set>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    multiset<ll> neg, nneg;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        if(a >= 0){
            nneg.insert(a);
        }else{
            neg.insert(a);
        }
    }

    ll ans = accumulate(nneg.begin(), nneg.end(), 0LL);
    for(auto a : neg){ ans -= a; }

    if(neg.size() % 2 == 1){
        ll tmpneg = *neg.rbegin();
        if(nneg.size()){
            ll tmpnneg = *nneg.begin();
            if(-tmpneg > tmpnneg){
                ans -= 2 * tmpnneg;
            }else{
                ans += 2 * tmpneg;
            }
        }else{
            ans += 2 * tmpneg;
        }
    }

    cout << ans << endl;
    return 0;
}
