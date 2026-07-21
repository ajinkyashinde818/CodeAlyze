#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int A, B;
	scanf("%d %d", &A, &B);
	int t;
	if (A > B) {
		t = A;
		A = B;
		B = t;
	}
	int64_t a = A;
	while (a % B)
		a += A;
	printf("%ld\n", a);
	return 0;
}
