#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;
char sn[55][55], sm[55][55];
bool flag, ok;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)scanf("%s", &sn[i]);
	for(int i = 0; i < m; i++)scanf("%s", &sm[i]);
	for(int i = 0; i <= n - m; i++){
		for(int j = 0; j <= n - m; j++)
		{
			flag = 0;
				if(sn[i][j] == sm[0][0])
				{
					for(int k = 0; k < m; k++)
						for(int s = 0; s < m; s++)
							if(sn[i + k][j + s] != sm[k][s])
							{
								flag = 1;
							}
				if(flag == 0){ok = 1;break;}
				}
		}
		}
		if(ok)printf("Yes\n");
		else printf("No\n");
}
