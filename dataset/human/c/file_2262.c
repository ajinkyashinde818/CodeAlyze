#include<stdio.h>

int main()
{
	char buf[1002];
	int field[2][1000];
	int i,j,n,max,tmp;

	while(1)
	{
		scanf("%d",&n);
		if(n==0){break;}
		max=0;

		for(i=0;i<=n;i++)
		{
			fgets(buf,n+2,stdin);
			for(j=0;j<n;j++)
			{
				if(i==0)
				{
					if(buf[j]=='*')
					{
						field[0][j]=0;
					}
					else
					{
						field[0][j]=1;
					}
				}				
				else
				{
					if(buf[j]=='*')
					{
						field[1][j]=0;
					}
					else
					{
						if(j>0)
						{
							tmp=field[0][j-1];
							if(tmp>field[0][j])tmp=field[0][j];
							if(tmp>field[1][j-1])tmp=field[1][j-1];
						}
						else{tmp=0;}
						field[1][j]=tmp+1;
						if(field[1][j]>max)max=field[1][j];
					}
				}
			}
			if(i>0)
			{
				for(j=0;j<n;j++)
				{
					field[0][j]=field[1][j];
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
