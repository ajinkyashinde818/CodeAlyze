#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <cassert>
#define SIZE 1005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int id[SIZE][SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	int k=1,sum=0;
	while(sum<n)
	{
		sum+=k;
		k++;
	}
	if(sum>n)
	{
		puts("No");
		return 0;
	}
	int now=1;
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			id[i][j]=id[j][i]=now++;
		}
	}
	puts("Yes");
	printf("%d\n",k);
	for(int i=0;i<k;i++)
	{
		printf("%d",k-1);
		for(int j=0;j<k;j++)
		{
			if(j==i) continue;
			printf(" %d",id[i][j]);
		}puts("");
	}
	return 0;
}
