#include <bits/stdc++.h>
using namespace std;
char a[100][100], b[100][100];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		scanf("%s", a[i] + 1);
	for(int i = 0; i < m; i ++)
		scanf("%s", b[i]);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
		{
			int flag = 0;
			for(int x = 0; x < m; x ++)
				for(int y = 0; y < m; y ++)
					if(a[i + x][j + y] != b[x][y]) flag = 1;
			if(flag == 0) {cout << "Yes"; return 0;}
		}

	cout << "No";

	return 0;
}
