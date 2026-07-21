#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//https://atcoder.jp/contests/abc145/tasks/abc145_d
const long int modo = 1000000007;
const long int modo2 = 1000000005;

long long int powMod(long long int a, long long int b){
    long long int x=1, y = a;
    while(b > 0){
        if(b%2==1){
            x = (x*y);
            if(x > modo) 
                x %= modo;
        }
        y = (y * y);
        if(y > modo) 
            y %= modo;
        b/=2;
    }
    return x;
}
 
 
long long int inverseEuler(long long int n){
    return powMod(n, modo2);
}

 
long long int C(long long int n, long long int r){
    long long int i, *f = malloc((n + 1) * sizeof(long long int));
    f[0] = 1;
    f[1] = 1;
    for(i = 2;i<=n;i++){
        f[i] = (f[i-1]*i);
        if(f[i] > modo)
            f[i] %= modo;
    }
 
    return (f[n]*((inverseEuler(f[r]) * inverseEuler(f[n-r]))%modo))%modo;
}
int main() {
	long int x, y, n1, N;
	scanf("%ld %ld\n", &x, &y);
	n1 =  (x < y) ? (2 * x - y) / 3 : (2 * y - x) / 3;
	N = y + x;
	if((N % 3 != 0) || n1 < 0 || n1 > N)
	    printf("0\n");
	else{
	    N /= 3;
	    printf("%lld\n", C(N, n1));
	}
	return 0;
}
