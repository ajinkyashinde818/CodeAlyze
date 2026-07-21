#include <bits/stdc++.h>
using namespace std;
long long int s[200005];
int main(){
    int n;
    cin >> n;
    long long int a[n];
    long long int sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
        s[i+1]=s[i]+a[i];
    }
    long long int ans=1e18;
    for(int i=1;i<n;i++)ans=min(ans,abs(sum-s[i]*2));
    cout << ans;
}
