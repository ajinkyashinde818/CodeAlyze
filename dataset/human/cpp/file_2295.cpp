#include <bits/stdc++.h>
using namespace std;

int main() {
    int  n, cnt=0,x=1000000000;
    long long ans=0;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        ans+=abs(a[i]);
        x=min(x, abs(a[i]));
        if(a[i]<0) cnt++;
    }
    sort(a.begin(), a.end());
    if(cnt%2!=0) {
        ans-=(2*x);
    }
    cout <<ans;
}
