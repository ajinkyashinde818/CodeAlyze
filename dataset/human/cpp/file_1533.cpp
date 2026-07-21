/**********************************************
 *Author*        :jxf378440404
 *Created Time*  : 2018/10/27 20:08:33

*********************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
const int MaxN = 1e5;
const int Inf = 1 << 30;

int vis[MaxN + 5];
int pos[MaxN + 5];
int flag[3000][3000];

int main()
{
	int n,a,cnt;
	while(~scanf("%d",&n)){
		a = sqrt(2 * n);
		for(int i = 1; i <= n;i++) vis[i] = 0,pos[i] = 0;
		if(a * (a + 1) == n * 2){
			printf("Yes\n");
			printf("%d\n",a + 1);
			for(int i = 1;i <= a + 1;i++){
				for(int j = 1;j <= a + 1;j++) flag[i][j] = 0;
			}
			for(int i = 1;i <= a + 1;i++){
				cnt = 0;
				printf("%d",a);
				for(int j = 1;j <= n;j++){
					if(vis[j] == 2) continue;
					else if(vis[j] == 1){
						if(flag[pos[j]][i] == 0){
							flag[pos[j]][i]++;
							vis[j]++;
							printf(" %d",j);
							cnt++;
						}
					}
					else{
						printf(" %d",j);
						cnt++;
						vis[j]++;
						pos[j] = i;
					}
					if(cnt == a) break;
				}
				printf("\n");
			}
		}
		else printf("No\n");
	}
    return 0;
}
