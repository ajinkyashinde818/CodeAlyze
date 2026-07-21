#include <stdio.h>
#include <math.h>

int main(){
	int a, n, i, j, z, s[10000], ans;
	while(scanf("%d", &n) != 0){
		if(n == 0) break;
		if(n == 0){
			printf("1\n");
			continue;
		}
		ans = 0;
		s[0] = 2;
		a = 1;
		for(i = 3; i <= 104729; i += 2){
			z = 0;
			for(j = 0; s[j] * s[j] <= i; j++){
				if(i % s[j] == 0){
					z = 1;
					break;
				}
			}
			if(z == 0){
				s[a] = i;
				a++;
				if(a == n) break;
			}
		}
		for(i = 0; i < a; i++) ans += s[i];
		printf("%d\n", ans);
	}
	return 0;
}
