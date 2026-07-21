#include<stdio.h>
int main() {

	int n, i, d1[100], d2[100], count = 0;
	int flag = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d%d", &d1[i], &d2[i]);

		if (d1[i] == d2[i])
			count++;
		else
			count = 0;

		if (count == 3)
			flag = 1;
	}

	if (flag == 1)
		printf("Yes");
	else
		printf("No");

	return 0;
}
