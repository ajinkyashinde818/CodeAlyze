#include <bits/stdc++.h>
using namespace std;
char A[60][60];
char B[60][60];
int n,m;
bool match(int x,int y){
	for (int i=0; i <m; ++i)
	{
		for(int j=0;j<  m;++j)
		{
			if(A[y+i][x+j]!=B[i][j]) return false;
		}
	}
	return true;
}
int main(){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",A[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%s",B[i]);
	}
	for (int y = 0; y <= n-m; ++y)
	{
		for (int x = 0; x <= n-m; ++x)
		{
			if(A[y][x] == B[0][0] && match(x,y)){
				printf("Yes\n");
				return 0;
			} 
		}
	}
	printf("No\n");
	return 0;

}
