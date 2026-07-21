#include<stdio.h>
#include<stdlib.h>
const long mod = 1000000007l;
int N, K, p=0, n=0;
long posi[1<<18], nega[1<<18], ans = 1;
int cmp(const void *a, const void *b){
	return abs(*(int*)b) - abs(*(int*)a);
}
int main(){
	scanf("%d%d", &N, &K);
	if(N == K){
		long ans = 1;
		while(N--){
			long A;
			scanf("%ld", &A);
			ans *= A;
			ans %= mod;
		}
		printf("%ld\n", (ans + mod) % mod);
		return 0;
	}
	for(int i=0; i<N; i++){
		long A;
		scanf("%ld", &A);
		if(A < 0){
			nega[n++] = A;
		}else {
			posi[p++] = A;
		}
	}
	qsort(nega, n, sizeof(long), cmp);
	qsort(posi, p, sizeof(long), cmp);
	if((p==0 || N==K) && K&1){
		for(int i=0; i<K; i++){
			ans = ans * (nega[n-i-1] + mod) % mod;
		}
		printf("%ld\n", ans);
		return 0;
	}
	int np = 0, nn = 0;
	while(K){
		if(p-np <= 1 || n-nn <= 1){
			if(K == 1){
				if(p > np){
					ans *= posi[np++];
					ans %= mod;
					K--;
				}else return 1;
			}else{
				if(p-np <= 1){
					ans *= nega[nn] * nega[nn+1] % mod;
					ans %= mod;
					K -= 2;
					nn += 2;
				}else {
					ans *= posi[np++];
					ans %= mod;
					K--;
				}
			}
		}else {
			if(posi[np] * posi[np+1] > nega[nn] * nega[nn+1] || K==1){
				ans *= posi[np++];
				ans %= mod;
				K--;
			}else {
				ans *= nega[nn] * nega[nn+1] % mod;
				ans %= mod;
				nn += 2;
				K -= 2;
			}
		}
	}
	printf("%ld\n", ans);
	return 0;
}
