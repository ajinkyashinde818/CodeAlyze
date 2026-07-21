#include <stdio.h>

long long abs(long long a) {
	if ( a < 0 ) return -a;
	return a;
}

long long min ( long long a, long long b ) {
	if ( a < b ) return a;
	return b;
}

int main(void) {
	int n,a[200000];
	long long s[200001] = {0};
	scanf("%d",&n);
	for(int i = 0;i < n;i++) {
		scanf("%d",&(a[i]));
		s[i+1] = s[i] + a[i];
	}
	long long res = 200000000000;
	for(int i = 1;i < n;i++) {
		res = min(res,abs((s[n]-s[i])-s[i]));
	}
	printf("%d",res);
}
