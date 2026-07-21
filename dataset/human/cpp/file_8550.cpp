#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<pii, ll>pi3;
ll mod = 1000000007;
char a[50][50], b[50][50];
int main()
{
	int na, nb;
	scanf("%d%d", &na, &nb);
	for (int i = 0; i < na; i++)scanf("%s", a[i]);
	for (int i = 0; i < nb; i++)scanf("%s", b[i]);
	for (int i = 0; i < na - nb + 1; i++)
	{
		for (int j = 0; j < na - nb + 1; j++)
		{
			bool f = true;
			for (int k = 0; k < nb; k++)for (int l = 0; l < nb; l++)
				if (a[k + i][l + j] != b[k][l])f = false;
			if (f)
			{
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
}
