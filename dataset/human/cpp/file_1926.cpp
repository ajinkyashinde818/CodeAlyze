#include <iostream>
#include <cstdint>
#include <cstdio>
using namespace std;

int main() {
	int q;
	uint32_t x;
	uint32_t i;
	double d;
	
	cin >> q;
	while(q--) {
		scanf("%08x", &x);
		
		i = (x << 1) >> 8;
		d = (x << 25) >> 25;
		
		for (int j = 0; j < 7; j++) d /= 2;
		
		if (x & (1 << 31)) putchar('-');
		if (d == 0.0) printf("%u.0\n", i);
		else {
			printf("%u.", i);
			while (d - (int)d > 0) {
				d *= 10;
				printf("%d", (int)d);
				d -= (int)d;
			}
			putchar('\n');
		}
	}
	
	return 0;
}
