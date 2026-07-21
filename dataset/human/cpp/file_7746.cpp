#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    int N; cin>>N;
    vector<ll> a(N,0);
    ll X=0;
    for(int i=0;i<N;i++){
        cin>>a[i];
        X+=a[i];
    }
    vector<ll> x(N,0);
    x[0]=a[0];
    for(int i=1;i<N;i++){
        x[i]=x[i-1]+a[i];
    }

    ll mini=2000000009;
    for(int i=0;i<N-1;i++){
        mini=min(mini,abs(2*x[i]-X));
    }
    cout<<mini;
    return 0;
}
