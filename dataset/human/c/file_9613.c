#include<stdio.h>
#include<string.h>
int N,M,i,j,k,P[105],r;
char S[105][9],t[9];
int main()
{
	for(;scanf("%d%d\n",&N,&M),N+M;)
	{
		for(i=r=0;i<N;i++)scanf("%s%d",S[i],P+i);
		for(i=0;i<M;i++)
		{
			scanf("%s",&t);
			for(k=0;k<N;k++)
			{
				for(j=0;S[k][j];j++)
					if(S[k][j]!='*'&&S[k][j]!=t[j])
						break;
				if(!S[k][j])
					r+=P[k];
			}
		}
		printf("%d\n",r);
	}
	return 0;
}
