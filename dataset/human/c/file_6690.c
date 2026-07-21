#include <stdio.h>
#include <string.h>

int main(void)
{
	int ans;
	int n;
	int m;
	char graph[500][500];
	char f[500];
	char ff[500];
	
	while (1){
		memset(graph, 0, sizeof(graph));
		memset(f, 0, sizeof(f));
		memset(ff, 0, sizeof(ff));
		
		scanf("%d%d", &n, &m);
		
		if (n == 0 && m == 0){
			break;
		}
		
		for (int i = 0; i < m; i++){
			int s, e;
			
			scanf("%d%d", &s, &e);
			graph[s - 1][e - 1] = graph[e - 1][s - 1] = 1;
		}
		
		for (int i = 0; i < n; i++){
			if (graph[0][i] == 1){
				f[i] = 1;
			}
		}
		
		for (int i = 0; i < n; i++){
			if (f[i] == 1){
				for (int j = 0; j < n; j++){
					if (graph[i][j] == 1){
						ff[j] = 1;
					}
				}
			}
		}
		
		ans = 0;
		for (int i = 1; i < n; i++){
			if (f[i] | ff[i] == 1){
				ans++;
			}
		}
		
		printf("%d\n", ans);
	}
	
	return (0);
}
