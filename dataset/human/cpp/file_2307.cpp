#include <iostream>

using namespace std;
long long n,i,a[200005],dp[2][200005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    dp[0][1]=a[1];
    dp[1][1]=-a[1];
    for(i=2;i<=n;i++)
    {
        dp[0][i]=max(dp[0][i-1]+a[i], dp[1][i-1]+-a[i]);
        dp[1][i]=max(dp[0][i-1]+-a[i], dp[1][i-1]+a[i]);
    }
    cout<<dp[0][n];
    return 0;
}
