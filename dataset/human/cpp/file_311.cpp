#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int r,g,b,n;
int abs(double x)
{
	return x>0?x:-x;
}
int main ()
{
	scanf("%d%d%d%d",&r,&g,&b,&n);
	int ans=0;
	int x,y;
	double z=0;
	for(x=0;x<=n/r;x++)	
		for(y=0;y<=n/g;y++)
		{
			//cout<<n-r*x-g*y<<" ";
			z=(double)(n-r*x-g*y)/b;
			//cout<<z<<" ";
			//cout<<(int)z<<" ";
			if(z==(int)z&&z==abs(z)) ans++;
			else 
			{
				z=0;
				continue; 
			}
			//cout<<ans<<endl;
		}
	printf("%d\n",ans);
	return 0;
}
