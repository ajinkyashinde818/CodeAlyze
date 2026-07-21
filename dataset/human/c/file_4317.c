#include <stdio.h>
#include <stdlib.h>

long fib(int n){
	if(n < 0)return 0;
	long a = 1, b = 1;
	long tmp;
	while(n){
		tmp = a;
		a += b;
		b = tmp;
		if(b > 1000000007)b -= 1000000007;
		if(a > 1000000007)a -= 1000000007;
		n--;
	}
	return b;
}

int main(void){
	//memo[0] = 1;
	int n, m;
	long ans = 1;
	int last = 0;
	int in;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &in);
		ans *= fib(in - last - 1);
		if(ans > 1000000007)ans %= 1000000007;
		last = in + 1;
	}
	ans *= fib(n - last);
	printf("%ld\n", ans % 1000000007);
	return 0;
}
