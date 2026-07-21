#include<stdio.h>
#include<string.h>
int main()
{
	int c[8],i,j,k,t;
	for(i=0;~scanf("%d",&c[i++]);)
	{
		if(i==8)
		{
			int m[8]={1,4,1,4,1,2,1,2},r[8]={9},w=1<<30;
			for(j=0;j<8;j++)
			{
				t=m[0];
				memmove(m,m+1,7*4);
				m[7]=t;
				for(k=t=0;k<8;k++)
					t+=c[k]-m[k]<=0?0:c[k]-m[k];
				if(w>t||(w==t&&memcmp(m,r,32)<0))
					w=t,memcpy(r,m,32);
			}
			for(j=0;j<8;j++)
				printf("%d%s",r[j],j==7?"\n":" ");
			i=0;
		}
	}
	return 0;
}
