#include <stdio.h>
#include <math.h>

int prime[200000];

void Eratos(void);

int main(void){
	int n;
	int p[10000];
	int num = 0;
	int ans;

	Eratos();

	for(int i=0; num < 10000; i++){
		if(prime[i] == 1){
			p[num] = i;
			num++;
		}
	}

	while(1){
		ans = 0;
		scanf("%d", &n);
		if(n == 0) break;

		for(int i=0; i<n; i++){
			ans += p[i];
		}

		printf("%d\n", ans);
	}

	return 0;
}

void Eratos(void){
	for(int i=0; i<200000; i++){
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;

	for(int i=2; i<sqrt(200000); i++){
		for(int j=2; i*j <= 200000; j++){
			prime[i*j] = 0;
		}
	}
}
