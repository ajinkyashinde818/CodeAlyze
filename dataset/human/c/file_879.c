#include<stdio.h>
int main(){
	long int N, Naux;
	scanf("%ld", &N);
	Naux = N;
	int ans = 0;
	for(long int n = 2; n * n <= Naux; n++){
		if(N % n == 0){
			N /= n;
			int nDiv = 1;
			while(N % n == 0){
				N /= n;
				nDiv++;
			}
			for(int i = 1; i*(i+1)/2 <= nDiv; i++)
				ans++;
		}
	}
	ans += N > 1 ? 1 : 0;
	printf("%d", ans);
	return 0;
}
