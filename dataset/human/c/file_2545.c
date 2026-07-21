#include <stdio.h>

int main(void)
{
	char x;
	int i;
	int a = 0, b = 0, c = 0;

	for(int i = 0; i < 3; i++) {
		x = getchar();
		if(x == 'a') { a++; }
		if(x == 'b') { b++; }
		if(x == 'c') { c++; }
	}

	if(a && b && c) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
}
