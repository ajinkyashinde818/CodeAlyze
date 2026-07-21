#include <bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int main()
{
	int n;
	scanf("%d", &n);
	int a = sqrt(2*n);
	int upto = 0;
	if (a * (a+1) == 2*n)
	{
		for (int i = 0; i < a+1; i++)
		{
			for (int j = 0; j < i; j++)
			{
				v[i].push_back(v[j][i-1]);
			}
			while (v[i].size() < a) v[i].push_back(++upto);
		}
		printf("Yes\n%d\n", a+1);

		for (int i = 0; i < a+1; i++)
		{
			printf("%lu ", v[i].size());
			for (auto c : v[i]) printf("%d ", c);
			printf("\n");
		}
	}
	else
	{
		printf("No\n");
	}
}
