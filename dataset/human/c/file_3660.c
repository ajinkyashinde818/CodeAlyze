#include <stdio.h>

int gcd(int x, int y){
    int r;

    while((r = x % y) != 0){
        x = y;
        y = r;
    }
    return y;
}

long long lcm(int x, int y){
    return ((long long)x * y / gcd(x, y));
}

int main() {
	long long a,b;
	scanf("%lld%lld", &a,&b);
	printf("%lld\n", lcm(a,b));
	return 0;
}
