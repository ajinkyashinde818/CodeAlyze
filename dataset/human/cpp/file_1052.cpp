#include<bits/stdc++.h>
using namespace std;
int dp[3010][3010];
int coinChange(int coin[],int n,int x,int y,int val)
{
    //cout<<"a"<<endl;
    if(x>=n)
    {
        if(y==val)
            return 1;
        else
     return 0;
    }
    if(dp[x][y]!=-1)
        return dp[x][y];
    int ret1=0,ret2=0;
    if(y+coin[x]<=val)
        ret1=coinChange(coin,n,x,y+coin[x],val);
        ret2=coinChange(coin,n,x+1,y,val);
        return dp[x][y]= ret1 + ret2;
}
int main()
{
    int n,val;

    int coin[30];

    memset(dp,-1,sizeof(dp));
    for(int i=0;i<3;i++)
    {
        cin>>coin[i];
    }
    cin>>val;
    int  k=coinChange(coin,3,0,0,val);
    cout<<k<<endl;
}
