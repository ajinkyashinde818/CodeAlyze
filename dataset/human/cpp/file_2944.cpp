#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1e5+10;
typedef long long ll;
const ll inf=1e18;
int n,a[N],b[N];
ll dp[N][2];//0-fu,1-zheng
int main(){
	//freopen("a.in","r",stdin);
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=abs(a[i]);
	dp[1][0]=dp[1][1]=-inf;
	dp[1][(a[1]>0)]=a[1];
	for(int i=2;i<=n;i++)
		if(a[i]>0){
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i];
			dp[i][0]=max(dp[i-1][0]+2*b[i-1]-a[i],dp[i-1][1]-2*b[i-1]-a[i]);
		}else{
			dp[i][0]=max(dp[i-1][0],dp[i-1][1])+a[i];
			dp[i][1]=max(dp[i-1][0]+2*b[i-1]-a[i],dp[i-1][1]-2*b[i-1]-a[i]);
		}
	cout<<max(dp[n][0],dp[n][1]);
}
