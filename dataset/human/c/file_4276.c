#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include <math.h>

#define mod 1000000007
/*
long long int Fibo(int n) {
	return round((pow((1 + sqrt(5)) / 2, n)
		- pow((1 - sqrt(5)) / 2, n)) / sqrt(5));
}
*/
long long int Fibo(int n) {
	int i, a, b, c;
	for (i = 0, b = 1, c = 0; i < n; i++) {
		a = b;
		b = c;
		c = a + b;
		c %= mod;
	}
	return c;
}

int main(){

	int i, j, k, N, M, *a;	
    long long int sum = 1, result;

	scanf("%d %d", &N, &M);

	if (M == 0){//危険マスがない場合はスタートからゴールまですぐ計算
		printf("%lld\n", Fibo(N+1) % mod);
		return 0;
	}

	a = (int *)malloc(M * sizeof(int));

	for (i = 0; i < M; i++)
		scanf("%d", &a[i]);
	
	if (M != 1){ // 連続した危険マスが隣接していたら０を返す
		for (i = 0; i < M; i++){
			if (a[i + 1] - a[i] == 1){
				printf("0\n");
				return 0;
			}
		}
	}

	sum *= Fibo(a[0]);//スタートから最初のブロック(直前)までの総数
	sum %= mod;

	for (i = 0; i < M-1; i++){//最初のブロックから最後のブロックまでの総数計算
		sum *= (Fibo(a[i + 1] - a[i]-1) % mod);
		sum %=mod;
	}

	sum *= (Fibo(N - a[M - 1]) % mod);//最後のブロックからゴールまでの総数

	result = sum % mod;
	printf("%lld\n", result);

  return 0;
}
