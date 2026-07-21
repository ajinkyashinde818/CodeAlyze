#include<stdio.h>

int main(){
	int l, m, n, i, ans = 0, a, b, c, d;
	scanf("%d %d %d", &l, &m, &n);
	scanf("%d %d", &a, &b);
	for (i = 1; i < n; i++){
		scanf("%d %d", &c, &d);
		while (1){
			if (a == c && b == d) break;
			ans++;
			if (a < c && b < d){
				a++;
				b++;
				continue;
			}
			if (a > c && b > d){
				a--;
				b--;
				continue;
			}
			if (a < c){
				a++;
				continue;
			}
			if (b < d){
				b++;
				continue;
			}
			if (a > c){
				a--;
				continue;
			}
			if (b > d){
				b--;
				continue;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
