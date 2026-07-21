#include<stdio.h>
int main(void) {
	int a, b, c;
	int ten;
	int ans[1000];
	int i, j=0;
	int count=0;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	if (a < b) {
		ten = a;
	}
	else {
		ten = b;
	}

	for (i = 1; i <= ten; i++) {
		if (a%i == 0 && b%i == 0) {
			ans[j] = i;
			j++;
			count++;
		}
	}

	printf("%d\n",ans[count-(c)]);
	return 0;
}
