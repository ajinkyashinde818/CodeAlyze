#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+5];
    int frr[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        frr[i]=(-1)*arr[i];
    }
    long long dp[n+5][2];
    dp[0][0]=0;
    dp[0][1]=-999999999;
    for(int i=0;i<n;i++)
    {
        dp[i+1][0]=max(dp[i][0]+arr[i],dp[i][1]-arr[i]);
        dp[i+1][1]=max(dp[i][0]-arr[i],dp[i][1]+arr[i]);
    }
    cout<<dp[n][0]<<endl;
}
