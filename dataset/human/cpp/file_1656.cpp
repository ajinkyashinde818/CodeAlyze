#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;
typedef long long LL;
const int inf = 1 << 30;
const LL INF = 1LL << 60;
const int MaxN = 100000;

/*
10
5
4  1 2 3 4
4  1 5 6 7
4  2 5 8 9
4  3 6 8 10
4  4 7 9 10


6
4
3  1 2 3
3  1 4 5
3  2 4 6
3  3 5 6
*/

int n;
int ans[505][505];

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		int tmp = (int)sqrt(2.0 * n);
		if(tmp * (tmp + 1) != 2 * n) printf("No\n");
		else {
			printf("Yes\n");
			printf("%d\n", tmp + 1);
			int sta = 1;
			for(int col = 1; col <= tmp; col++) {
				for(int j = col; j <= tmp; j++) {
					ans[col][j] = sta + (j - col);

					ans[j + 1][col] = sta + (j - col);
				}
				sta += (tmp - col + 1);
			}
			for(int i = 1; i <= tmp + 1; i++) {
				printf("%d", tmp);
				for(int j = 1; j <= tmp; j++) printf(" %d", ans[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}
