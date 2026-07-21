#include<stdio.h>
#include<string.h>
int N,i,j,k,l,P[1005];
char S[1000][1060];

int main()
{
	for(;scanf("%d\n",&N),N;)
	{
		for(i=0;i<N;i++)gets(S[i]);
		for(i=0;i<N;i++)
		{
			for(j=0;S[i][j]=='.';j++);
			P[i]=j;
		}
		for(i=0;i<N;i++)
		{
			for(j=0,l=strlen(S[i]);j<l;j++)
			{
				if('a'<=S[i][j]&&S[i][j]<='z')break;
				else if('a'<=S[i][j+1]&&S[i][j+1]<='z')
				{
					S[i][j]='+';
					for(k=i+1;k<N&&P[k]>P[i];k++);
					if(k!=N&&P[k]==P[i])
						for(k=k-1;k>i;k--)
							S[k][j]='|';
				}
				else if(S[i][j]=='.')
					S[i][j]=' ';
			}
			puts(S[i]);
		}
	}
	return 0;
}
