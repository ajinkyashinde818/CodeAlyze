#include <stdio.h>
#define N 200005
int n, i, j, k, f, a, c, t[N], v[N];
long long m;
int main(){
	scanf("%d%lld", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &t[i]);
	}
	for(a=1; m; m--){
		a = t[a], c++;
		if(v[a]) break;
		v[a] = c;
	}
	if(m == 0) printf("%d\n", a);
	else{
		c = c - v[a];
		m = --m % c;
		for(; m; m--) a = t[a];
		printf("%d\n", a);
	}
	return 0;
}
