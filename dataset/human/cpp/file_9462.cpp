#include <cstdio>
#include <iostream>
using namespace std;

char N[55][55],M[55][55];
int n,m;

bool isSame(int startX, int startY)
{
	for(int k=1;k<=m;k++)
		for(int l=1;l<=m;l++)
			if(N[startX+k-1][startY+l-1]!=M[k][l])
				return false;

	return true;
} 

int main()
{   
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>N[i][j];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			cin>>M[i][j];

	for(int i=1;i<=n-m+1;i++)
		for(int j=1;j<=n-m+1;j++)
			if(isSame(i,j))
			{
				printf("Yes\n");
				return 0;
			}


	printf("No\n");
	return 0;
}
