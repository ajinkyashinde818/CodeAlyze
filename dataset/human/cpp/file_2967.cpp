#include<bits/stdc++.h>

using namespace std;

long long sec[100010];
long long dp[100010][2];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>sec[i];
    }
    dp[1][0]=sec[1];
    dp[1][1]=0x8f8f8f8f8f8f8f8f;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=max(dp[i-1][1],dp[i-1][0])+sec[i];
        dp[i][1]=max(dp[i-1][1]+2*sec[i-1],dp[i-1][0]-2*sec[i-1])-sec[i];
    }
    cout<<max(dp[n][0],dp[n][1])<<'\n';
}
