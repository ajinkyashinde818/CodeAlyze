#include <iostream>
using namespace std;

const int maxn=1e5+1;
int n,i,dir,times;
long long C,ans,x[2][maxn],v[2][maxn],sum[3][2][maxn];

int main()
{
	cin>>n>>C;
  	for(i=1;i<=n;i++)
    {
      	cin>>x[0][i]>>v[0][i];
      	x[1][n+1-i]=C-x[0][i];
      	v[1][n+1-i]=v[0][i];
    }
  	for(dir=0;dir<2;dir++)
    	for(i=1;i<=n;i++)
      		v[dir][i]+=v[dir][i-1];
  	for(times=0;times<2;times++)
    	for(dir=0;dir<2;dir++)
    		for(i=1;i<=n;i++)
	  			sum[times][dir][i]=max(sum[times][dir][i-1],v[dir][i]-(times+1)*x[dir][i]);
  	for(i=0;i<=n;i++)
    ans=max(ans,max(sum[0][0][i]+sum[1][1][n-i],sum[0][1][i]+sum[1][0][n-i]));
  	cout<<ans;
}
