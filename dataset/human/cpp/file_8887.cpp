#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int n,m;
	string a[50],b[50];

	scanf("%d %d", &n,&m);

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}


	for(int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	bool check;

	for(int i = 0; i <= n-m; i++)
	{
		for(int j = 0; j <= n-m; j++)
		{
			if (a[i][j] == b[0][0])
			{
				check = true;

				for(int k = 0; k < m; k++)
				{
					for(int l = 0; l < m; l++)
					{
						if (a[i+k][j+l] != b[k][l])
						{
							check = false;
							break;
						}

						if (k == m-1 && check)
						{
							printf("Yes\n");
							return 0;
						}
					}
				}
			}
		}
	}

	printf("No\n");

	return 0;
}
