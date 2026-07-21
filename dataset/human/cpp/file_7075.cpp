#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n),b(n);
    vector<ll>As(200020,0),Bs(200020,0);
    ll maxA=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        As[a[i]]++;
        maxA=max(maxA,a[i]);
    }
    for(ll i=0;i<n;i++){
        cin >> b[i];
        Bs[b[i]]++;
        maxA=max(maxA,b[i]);
    }

    for(ll i=0;i<=maxA;i++){
        if(As[i]+Bs[i]>n){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    reverse(b.begin(),b.end());
    ll t=-1;
    for(ll i=0;i<n;i++){
        if(a[i]==b[i]){
            t=a[i];
            break;
        }
    }

    if(t==-1){
        for(ll i=0;i<n;i++){
            cout << b[i] << " ";
        }
        cout << endl;
        return 0;
    }

    ll ib=0;
    for(ll i=0;i<n;i++){
        if(a[i]==b[i]){
            swap(b[ib],b[i]);
            ib++;
        }
    }

    ib=n-1;
    for(ll i=0;i<n;i++){
        if(a[i]==b[i]){
            swap(b[i],b[ib]);
            ib--;
        }
    }

    for(ll i=0;i<n;i++){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
