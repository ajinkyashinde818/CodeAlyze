#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll count=0;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<0) count++;
    }
    if(count%2==0){
        ll res=0;
        for(ll i=0;i<n;i++){
            res+=abs(a[i]);
        }
        cout << res << endl;
    }
    else{
        ll res=0;
        ll mmin=1e10;
        for(ll i=0;i<n;i++){
            mmin=min(mmin,abs(a[i]));
            res+=abs(a[i]);
        }
        res-=mmin*2;
        cout << res << endl;
    }
    return 0;
}
