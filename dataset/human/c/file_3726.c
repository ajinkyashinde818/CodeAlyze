#include"stdio.h"
#include"math.h"



int main() {
	long int a, b, ans;
	scanf("%ld %ld", &a, &b);
	int waru, warareru;
	if (a >= b) { warareru = a;waru = b; }
	else {warareru = b;waru = a;}

	int r = warareru % waru;
	while (r != 0) {
		warareru = waru;
		waru = r;
		r = warareru % waru;
	}

	ans = waru;
	printf("%ld",a*b/ans);
	return 0;
}
