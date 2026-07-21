#include <stdio.h>
#include <stdlib.h>
long long min(long long a, long long b){
	return a > b ? b: a;
}

int main(){
	long long int pre[200005], mindif;
	int n, read;
	scanf("%d%lld", &n, &pre[0]);
	for(int i = 1; i < n; ++i){
		scanf("%d", &read);
		pre[i] = pre[i-1] + read;
	}
	mindif = abs(pre[n-1] -pre[0] - pre[0]);//uma dif qualquer
	for(int i = 0; i < n-1; ++i){
		long long ma = pre[i], rog = pre[n-1] - pre[i];
		mindif = min(mindif, llabs(ma - rog));
	}
	printf("%lld\n", mindif);
	return 0;
}
