#include <bits/stdc++.h>
using namespace std;
int dp[3007];
int main(){
    int a[4],x;cin>>a[1]>>a[2]>>a[3]>>x;
    for(int i=0;i<=x;i++) for(int k=0;k<=i;k+=a[1]) if(!((i-k)%a[2])) dp[i]++;
    int ans=0;
    for(int i=0;i<=x;i++){if(!((x-i)%a[3])) ans+=dp[i];}
    cout<<ans;
    return 0;
}
