#include<stdio.h>

int main()
{
	int a, b, c, d, s1, s2;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);

	s1 = a * b;
	s2 = c * d;

	if (s1 < s2) {
		printf("%d\n", s2);
	}
	else {
		printf("%d\n", s1);
	}

	
	
	return 0;

}
