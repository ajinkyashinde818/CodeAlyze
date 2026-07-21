// ABC 148-C
// 2019.12.22 bal4u

#include <stdio.h>

typedef long long ll;

int gcd(int a, int b)
{
	int r;
	while (b != 0) r = a % b, a = b, b = r;
	return a;
}

ll lcm(int a, int b)
{
	return (ll)a/gcd(a, b)*b;
}

int main()
{
	int A, B;
	
	scanf("%d%d", &A, &B);
	printf("%lld\n", lcm(A, B));
	return 0;
}
