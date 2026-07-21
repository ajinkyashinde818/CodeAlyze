#include<stdio.h>
#include<string.h>
#define min(a,b) ((a)<(b)?(a):(b))
int N,i,j,s,t,C[1001][1001],m,A;
char M[1005][1005];

int main()
{
	for(;scanf("%d\n",&N),N;)
	{
		for(i=0;i<N;i++)
			gets(M[i]);
		for(i=0;i<N;i++)
			for(j=N-1;j>=0;j--)
			{
				if(M[j][i]=='*')C[j][i]=0;
				else if(j==N-1)C[j][i]=1;
				else C[j][i]=C[j+1][i]+1;
			}
		for(i=A=0;i<N;i++)
		{
			for(s=0;s<N;s++)
			{
				for(j=0,m=C[i][s];j<=m;j++)
				{
					if(m>C[i][s+j])
					{
						A=A>min(m,j)?A:min(m,j);
						m=C[i][s+j];
					}
				}
			}
			if(A==N)break;
		}
		printf("%d\n",A);
	}
	return 0;
}
