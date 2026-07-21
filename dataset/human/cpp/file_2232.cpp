#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    int mc=0;
    ll sum=0;
    ll mina=10000000009;
    for(int i = 0;i < n;++i) {
        cin>>a[i];
        if(a[i]<0)++mc;
        sum+=abs(a[i]);
        mina=min(mina,abs(a[i]));
    }

    if(mc%2==0){
        cout<<sum<<endl;
    }
    else cout<<sum-2*mina<<endl;


    return 0;
}
