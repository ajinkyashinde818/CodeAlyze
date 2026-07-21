#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 100005;

int n,ans;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];
int fa[MAXN];

bool exist;
bool mark[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int find(int v)
{
	int low = 1,high = n + 1;
	while (low < high)
	{
		int mid = low + high >> 1;
		if (c[mid] >= v)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		a[n + 1] ^= a[i];
	}
	for (int i = 1;i <= n;i++)
		if (a[i] == a[n + 1])
			exist = 1;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&b[i]);
		b[n + 1] ^= b[i];
	}
	bool ok = 1;
	for (int i = 1;i <= n;i++)
		if (a[i] != b[i])
		{
			ok = 0;
			break;
		}
	if (ok)
	{
		printf("0\n");
		return 0;
	}
	memcpy(c,a,sizeof(c));
	memcpy(d,b,sizeof(d));
	sort(c + 1,c + n + 2);
	sort(d + 1,d + n + 2);
	for (int i = 1;i <= n + 1;i++)
		if (c[i] != d[i])
		{
			printf("-1\n");
			return 0;
		}
	for (int i = 1;i <= n + 1;i++)
		fa[i] = i;
	for (int i = 1;i <= n + 1;i++)
		a[i] = find(a[i]);
	for (int i = 1;i <= n + 1;i++)
		b[i] = find(b[i]);
	for (int i = 1;i <= n + 1;i++)
		if (a[i] != b[i])
		{
			fa[getroot(a[i])] = getroot(b[i]);
			mark[getroot(b[i])] = 1;
			ans += (i <= n);
		}
	for (int i = 1;i <= n + 1;i++)
		if (i == fa[i] && mark[i])
			ans++;
	printf("%d\n",ans + (a[n + 1] == b[n + 1] && !exist) - 1);
	return 0;
}
