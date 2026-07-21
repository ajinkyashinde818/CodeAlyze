#include <stdio.h>
int n, m, x, i, j, k, ans=1e9;
int a[15][15], b[15], c[15];
void dfs(int k, int v){
	int i, j, s;
	if(v >= ans) return;
	if(k > n){
		for(j=1; j<=m; j++){
			s = 0;
			for(i=1; i<=n; i++){
				s += a[i][j] * b[i];
			}
			if(s < x) return;
		}
		ans = v;
	}
	else{
		for(i=0; i<=1; i++){
			b[k] = i;
			dfs(k+1, v+c[k]*i);
		}
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &x);
	for(i=1; i<=n; i++){
		scanf("%d", &c[i]);
		for(j=1; j<=m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	dfs(1, 0);
	if(ans < 1e9) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}
