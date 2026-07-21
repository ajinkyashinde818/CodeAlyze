#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <deque> 

using namespace std;


int r[3], n;
int nCount;

void doSearch(int d, int curNum)
{
	if (d == 2)
	{
		if ((n - curNum) % r[2] == 0)
//		{
			nCount++;// = nCount + (curNum / r[2]);
//		}
//		if (curNum == n)
//		{
////			printf("%d %d %d %d\n", r[0], r[1], r[2], curNum);
//			nCount++;
//		}
	}
	else
	{
		int newNum = curNum;
		while (newNum <= n)
		{
			doSearch(d + 1, newNum);
			newNum = newNum + r[d];
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &(r[0]), &(r[1]), &(r[2]), &n);
	
	nCount = 0;
	
	doSearch(0, 0);
	
	printf("%d\n", nCount);
	

	return 0;
}
