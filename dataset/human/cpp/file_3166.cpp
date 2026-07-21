#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int mn=1e9;
    int zero=0;
    int minus=0;
    ll sum=0;
    for (int i=0;i<n;i++) {
        int a;cin>>a;
        sum+=abs(a);
        mn=min(mn,abs(a));
        if (a==0)
            zero=1;
        else if (a<0) {
            minus++;
        }
    }
    if (zero||minus%2==0)
        cout<<sum<<endl;
    else
        cout<<sum-2*mn<<endl;
    return 0;
}
