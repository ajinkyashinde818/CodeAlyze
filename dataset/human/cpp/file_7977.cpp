#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<long long>a(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i==0)continue;
        sum+=a[i];
    }
    long long dp[200005];
    dp[0]=a[0];
    long long ans=abs(sum-dp[0]);
    for(int i=1;i<n-1;i++){
        dp[i]+=(dp[i-1]+a.at(i));
        sum-=a.at(i);
        ans=min(ans,abs(sum-dp[i]));
    }
    cout << ans << endl;
}
