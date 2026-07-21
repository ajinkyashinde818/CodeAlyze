#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LL long long
#define uLL unsigned long long
LL map[1000][1000];
int cmp(LL a,LL b,LL c,LL d)
{
	if (a==c)
	{
		return c-d;
	}
	else
	{
		return a-c;
	}
}
int islegal(char ch)
{
	if (ch=='.') {return 1;}
	if (ch=='#') {return 2;}
	return 0;
}
int solve(LL a,LL b)
{
	if (map[a][b]==2)
	{
		if (map[a-1][b]==2) {return 1;}
		if (map[a+1][b]==2) {return 1;}
		if (map[a][b+1]==2) {return 1;}
		if (map[a][b-1]==2) {return 1;}
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	//freopen("in.in","r",stdin);
	LL i,j,k,a,b,c,ans,n,m;
	char ch;
	scanf("%lld%lld",&n,&m);
	ans=0;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			while (1)
			{
				scanf("%c",&ch);
				if (islegal(ch)!=0) {break;}
			}
			map[i][j]=islegal(ch);
		}
	}
	for (i=0;i<=n+1;i++) {map[i][0]=1;map[i][m+1]=1;}
	for (i=0;i<=m+1;i++) {map[0][i]=1;map[n+1][i]=1;}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (solve(i,j)==0)
			{
				goto FAIL;
			}
		}
	}
	printf("Yes\n");
	return 0;
	FAIL:
	printf("No\n");
	return 0;
}
