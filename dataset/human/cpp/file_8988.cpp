#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

char A[105][105],B[105][105];

int N,M;
bool check(int sy,int sx)
{
	for(int i=0;i<M;i++)
		for(int j=0;j<M;j++)
			if(A[sy+i][sx+j]!=B[i][j])
				return false;
	return true;
}

int main()
{
	scanf("%d%d\n",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%s",A[i]);
	for(int i=0;i<M;i++)
		scanf("%s",B[i]);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(check(i,j))
			{
				puts("Yes");
				return 0;
			}
	puts("No");
	return 0;
}
