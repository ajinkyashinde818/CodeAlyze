#include<cstdio>
using namespace std;
int r,g,b,i,j,ans=0,n;
int main()
{
	scanf("%d%d%d%d",&r,&g,&b,&n);
	for(i=0;i*r<=n;i++)
	{
		for(j=0;j*g<=n-i*r;j++)
		{
			if((n-i*r-j*g)%b==0)ans++;	
		}	
	}	
	printf("%d\n",ans);
	return 0;
}
