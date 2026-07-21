#include <stdio.h>

long long int abs(long long int a){
	if(a < 0)
		return -a;
	else
		return a;
}

int main(){
	long long int N;
	long long int a[2*10*10*10*10*10*10];
	long long int result = 100000000000;
	long long int total_count = 0;
	long long int count = 0;

	scanf("%lld", &N);

	long long int i, j;
	for(i = 0; i < N; i++){
		scanf("%lld", &a[i]);
		total_count += a[i];
	}

	for(i = 0; i < N-1; i++){
		count += a[i];
		if(abs(total_count - 2*count) < result)
			result = abs(total_count - 2*count);
	}

	printf("%lld\n", result);

	return 0;
}
