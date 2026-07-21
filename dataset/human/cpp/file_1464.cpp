#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
typedef long long ll;
int arr[505][505], lst[505];
bool vis[100005];
int main()
{
	// freopen("TK1-D.in", "r", stdin);
	int n, k = 1;
	scanf("%d", &n);
	while (k * (k - 1) < 2 * n)
		k++;
	if (k * (k - 1) != 2 * n)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("%d\n", k);
	int cur = 0;
	for (int i = 0; i < k; i++)
	{
		printf("%d ", k - 1);
		for (int j = 0; j < i; j++)
		{
			while (vis[arr[j][lst[j]]])
				lst[j]++;
			arr[i][j] = arr[j][lst[j]];
			vis[arr[i][j]] = true;
		}
		for (int j = i; j < k - 1; j++)
			arr[i][j] = ++cur;
		for (int j = 0; j < k - 1; j++)
			printf("%d%c", arr[i][j], " \n"[j + 1 == k - 1]);
	}
	return 0;
}
