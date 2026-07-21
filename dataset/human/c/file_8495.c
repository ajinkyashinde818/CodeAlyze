#include<stdio.h>
#include<string.h>

int H,W=5,B[11][5],i,j,R;

int del()
{
	int i,j,k,t,r=0;
	for(i=0;i<H;i++)
		for(j=0;j<W;j++)
		{
			if(B[i][j]!=-1)
			{
				for(k=j+1;k<W&&B[i][j]==B[i][k];k++);
				if(k-j>=3)
				{
					r+=B[i][j]*(k-j);
					for(t=j;t<k;t++)B[i][t]=-1;
				}
			}
		}
	R+=r;
	return r;
}

void fall()
{
	int i,j,k,t;
	for(i=0;i<W;i++)
		for(j=H-1;j>=0;j--)
			if(B[j][i]!=-1)
			{
				for(k=j+1;k<H&&B[k][i]==-1;k++);
				k--;
				t=B[k][i];
				B[k][i]=B[j][i];
				B[j][i]=t;
			}
}

int main()
{
	for(;scanf("%d",&H),H;)
	{
		R=0;
		memset(B,-1,sizeof(B));
		for(i=0;i<H;i++)
			for(j=0;j<5;j++)
				scanf("%d",&B[i][j]);
		while(del()!=0)
		{
			fall();
		}
		printf("%d\n",R);
	}
	return 0;
}
