#include <bits/stdc++.h>
using namespace std;
using Int = long long;
Int const INF = 1e10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n; Int a[n];
    for (int i = 0; i < n; i++) cin>>a[i];
    for (int i = 1; i < n; i++) a[i]+=a[i-1];
    Int ans=INF;
    for (int i = 0; i < n-1; i++){
        ans=min(abs(a[i]-(a[n-1]-a[i])),ans);
    }
    cout<<ans<<'\n';
}
