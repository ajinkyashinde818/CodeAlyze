#include<stdio.h>
#include<math.h>
int W,H,N,i,x,y,nx,ny,r,p,q;

int mx(int a,int b){a=abs(a);b=abs(b);return a>b?a:b;}
int mn(int a,int b){a=abs(a);b=abs(b);return a<b?a:b;}
int main()
{
	scanf("%d%d%d",&W,&H,&N);
	scanf("%d%d",&nx,&ny);
	for(i=r=0;i<N-1;i++)
	{
		scanf("%d%d",&x,&y);
		p=nx-x;q=ny-y;
		if(p*q>0)
			r+=mx(p,q);
		else
			r+=abs(p)+abs(q);
		nx=x;
		ny=y;
	}
	printf("%d\n",r);
	return 0;
}
