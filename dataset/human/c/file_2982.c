#include <stdio.h>
#include <math.h>

/*
円周上にN個の箱が並んでいて、i番目の箱には石がA[i]個入っている。
次の操作を繰り返す：
ある箱を決めて、そこから番号昇順に1,2,...,N個の石を取り除く。
すべての箱を空にできるか？

まずA[i]の和をN(N+1)/2で割れば何回の操作が必要かわかる。回数をMとおく。ここで割り切れなかったらダメ。
つぎに、i番目の箱から始まった操作の回数をB[i]とおく。
i番目とi-1番目の箱の個数の差は、-(N-1)されることを考えると、
A[i] - A[i-1] = -B[i]*(N-1) + (M-B[i]) = -B[i] * N + M
よって、
B[i] = (-A[i] + A[i-1] +M) / N
となる。
*/

int main() {
	long long N,A[100000];
	long long i,M,B[100000];
	long long sum,P;
	scanf("%lld",&N);
	for(i=0;i<N;i++){
		scanf("%lld",&A[i]);
	}
	sum = 0;
	for(i=0;i<N;i++){
		sum = sum + A[i];
	}
	P = (N*(N+1))/2;
	if(sum % P == 0){
		M = sum/P;
	}else{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<N;i++){
		if((-A[i]+A[i-1]+M) <  0){
			printf("NO\n");
			return 0;
		}
	}
	for(i=1;i<N;i++){
		if((-A[i]+A[i-1]+M) % N != 0){
			printf("NO\n");
			return 0;
		}
	}
	if((-A[0]+A[N-1]+M) % N != 0){
			printf("NO\n");
			return 0;
	}
	if((-A[0]+A[N-1]+M) < 0){
			printf("NO\n");
			return 0;
	}
	printf("YES\n");
	return 0;
}
