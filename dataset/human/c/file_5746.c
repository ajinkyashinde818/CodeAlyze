#include <stdio.h>

int main()
{
	int n,R;
	scanf("%d", &n);
	scanf("%d", &R);
	int u = -2000000000;
	int l = R;
	while (--n) {
		scanf("%d", &R);
		if (u < (R - l)) u = R - l;
		if (l > R) l = R;
	}
	printf("%d\n", u);
}
