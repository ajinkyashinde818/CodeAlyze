#include <stdio.h>
#include <stdlib.h>
#define int long long

int min(int a, int b){
	return a <= b ? a : b;
}

signed main(){
	int A, B, C;
	scanf("%lld%lld%lld", &A, &B, &C);
	printf("%lld\n", B + min(C, A + B + 1));
	return 0;
}
