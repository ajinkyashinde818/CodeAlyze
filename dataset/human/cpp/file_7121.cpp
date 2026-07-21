#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll wa_upper[n];
    ll wa_under[n];
    wa_upper[0] = a[0];
    for(int i = 1; i < n; i++){
        wa_upper[i] = wa_upper[i - 1] + a[i];
    }
    wa_under[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--){
        wa_under[i] = wa_under[i + 1] + a[i];
    }

    /*for(int i = 0; i < n; i++){
        cout << wa_upper[i] << " " << wa_under[i] << endl;
    }*/

    ll wa_abs = 0;
    ll ans = -1;
    for(int i = 0; i < n - 1; i++){
        wa_abs = abs(wa_upper[i] - wa_under[i + 1]);
        if(ans == -1){
            ans = wa_abs;
        }else if(ans >= wa_abs){
            ans = wa_abs;
        }
    }

    cout << ans << endl;
}
