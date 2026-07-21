#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    ll ans = 0;
    ll min_a = 10000000000;
    ll x;
    int flag = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        ans += abs(x);
        if(abs(x) < min_a){
            min_a = abs(x);
        }
        if(flag == 1){
            x *= -1;
        }
        if(x < 0){
            flag = 1;
        }else{
            flag = 0;
        }
    }
    if(flag == 1){
        ans = ans - 2 * min_a;
    }
    cout << ans << endl;


}
