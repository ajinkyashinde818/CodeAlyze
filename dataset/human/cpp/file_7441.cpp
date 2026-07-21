#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans, x, y;
    vector<int> a(n);
    vector<long long> s(n+1);
    s[0]=0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        s[i+1]=s[i]+a[i];
    }
    for(int i=1; i<n; i++) {
        x=s[i];
        y=s[n]-s[i];
        if(i==1) ans=abs(x-y);
        else ans=min(ans, abs(x-y));
    }
    cout << ans;
}
