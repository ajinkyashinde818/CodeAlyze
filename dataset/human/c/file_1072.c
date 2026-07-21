#include<stdio.h>
int n,i,j,C[150];
char S[2][9],t,o[5]="mcxi";
int main()
{
	C[109]=0;C[99]=1;C[120]=2;C[105]=3;
	for(scanf("%d",&n);n--;)
	{
		int N[4]={0};
		scanf("%s%s",S[0],S[1]);
		for(j=0;j<2;j++)
			for(i=0;S[j][i];i++)
			{
				if('1'<S[j][i]&&S[j][i]<='9')
					t=S[j][i];
				else
				{
					N[C[S[j][i]]]+=t==0?1:t-'0';
					t=0;
				}
			}
		for(i=3;i>=0;i--)
			if(N[i]>=10)
			{
				N[i-1]++;
				N[i]-=10;
			}
		for(i=0;i<4;i++)
			if(N[i]!=0)
			{
				if(N[i]>1)printf("%d",N[i]);
				printf("%c",o[i]);
			}
		puts("");
	}
	return 0;
}
