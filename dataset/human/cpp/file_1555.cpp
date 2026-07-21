#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>

using namespace std;

int n; 
int useCount[100010];

int main()
{
	
	scanf("%d", &n);
	
	if (n == 1)
	{
		printf("Yes\n");
		printf("2\n");
		printf("1 1\n");
		printf("1 1\n");
		return 0;
	}
	
	if (n == 3)
	{
		printf("Yes\n");
		printf("3\n");
		printf("2 1 2\n");
		printf("2 2 3\n");
		printf("2 1 3\n");
		return 0;
	}	
	
//	if (n == 6)
//	{
//		printf("Yes\n");
//		printf("4\n");
//		printf("3 1 2 3\n");
//		printf("3 3 4 5\n");
//		printf("3 5 6 1\n");
//		printf("3 2 4 6\n");
//		return 0;
//	}
	
//	if (n == 10)
//	{
//		printf("Yes\n");
//		printf("4\n");
//		printf("4 1 2 3 4\n");
//		printf("4 4 5 6 7\n");
//		printf("4 1 5 8 10\n");
//		printf("4 2 6 8 9\n");
//		printf("4 3 7 9 10\n");
//		return 0;
//	}
	
	int m = n * 2;
	int p = 2;
	while ((p * (p + 1)) < m)
	{
		p++;
	}
	
	if ((p * (p + 1)) != m)
	{
		printf("No\n");
		return 0;
	}
	
	printf("Yes\n");
	printf("%d\n", p + 1);
	int limit = p + 1;
	
//	memset(useCount, 0, sizeof(useCount));
	std::queue<int> q[10010];
	printf("%d ", p);
	for (int j = 1 ; j <= p ; j++)
	{
		printf("%d ", j);
//		usedCount[j]++;
		q[1].push(j);
	}
	printf("\n");
	int newP = p + 1;
	
	for (int i = 1 ; i < limit ; i++)
	{
		printf("%d ", p);
		int oneCount = 1;
		int j = 1;
		while (oneCount <= i)
		{
			int temp = q[oneCount].front();
			printf("%d ", temp);
			q[oneCount].pop();
			oneCount++;
		}
		
		while (oneCount <= p)
		{
			printf("%d ", newP);
			q[i + 1].push(newP);
			newP++;
			oneCount++;
		}
		printf("\n");
	}
	
	return 0;
}
