#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>



const int mod = 1000000007;

int main() {
	int A, B, c;
	scanf("%d %d %d", &A, &B, &c);
	if (c <= A + B + 1) {
		printf("%d", c + B);
	}
	else {
		printf("%d", A + 2 * B + 1);
	}
}
