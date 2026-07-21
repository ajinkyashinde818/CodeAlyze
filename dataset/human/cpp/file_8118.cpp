#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int a[n];
    ll l=0,r=0,mn=1e18;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        r+=a[i];
    }
    for (int i=0;i<n-1;i++) {
        l+=a[i];
        r-=a[i];
        mn=min(mn,abs(l-r));
    }
    cout<<mn<<endl;
    return 0;
}
