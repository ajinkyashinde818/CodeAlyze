#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long c;
    cin >> n >> c;
    vector<long long> x(n), v(n);
    long long mx1=0, mx2=0, xs=0, ys=0;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> v[i];
        ys+=v[i];
    }
    long long ans=0;
    for (int i=0; i<=n; i++) {
        if ( i>0 ) xs+=v[i-1];
        if ( i>0 ) ys-=v[i-1];
        if ( i>0 ) ans=max(ans,xs-x[i-1]);
        if ( i<n ) ans=max(ans,ys-(c-x[i]));
        if ( i>0 ) mx1=max(mx1,xs-x[i-1]);
        if ( i>0 ) mx2=max(mx2,xs-x[i-1]*2);
        if ( i<n ) ans=max(ans,ys-(c-x[i])*2+mx1);
        if ( i<n ) ans=max(ans,ys-(c-x[i])+mx2);
    }
    cout << ans << '\n';
    return 0;
}
