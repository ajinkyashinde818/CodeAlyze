/*#include <stdio.h>
int main(void) {
	int n ,s1, e1, min, dis, a;
	char s2, e2;
	double p = 3.14259265;

	scanf("%d", &n);
	scanf("%d %c",&s1,&s2);
	scanf("%d %c",&e1,&e2);
	if (s1 - e1<0) {
		dis = e1 - s1;
		a = s1;
	}
	else {
		dis = s1 - e1;
		a = e1;
	}

	if (s2 == e2)
		min = dis * 100;
	else if ((s2 == 'S'&&e2 == 'N') || (s2 == 'N'&&e2 == 'S'))
		min = (e1 + s1) * 100;
	else if ((s2 == 'E'&&e2 == 'W') || (s2 == 'W'&&e2 == 'E'))
		min = (e1 + s1) * 100;
	else
		min = dis * 100 + (double)(a * 100 * p) / 2;

		printf("%ld\n", min);
	return 0;
}*/


/*
#include <stdio.h>

int main(void) {
	int n, m = 2, q[50], i, sum = 1;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &q[i]);
	}
	for (i = 0; i < n; i++) {
		do {
			if (q[i] % m == 0) {
				sum += m;
			}
			m++;
		} while (m<q[i]);
		if (q[i] == sum)
			printf("perfect\n");
		else if (q[i] == sum + 1 || q[i] == sum - 1)
			printf("nealy\n");
		else
			printf("neither\n");
	}
	return 0;
}*/


/*
#include <stdio.h>

int main(void) {
	int point = 0, n, d[1000], p[1000], i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &d[i], &p[i]);
	}
	for (i = 0; i < n; i++) {
		switch (d[i]) {
		case 3:
		case 13:
		case 23:
		case 30:
		case 31:
			point += (p[i] * 3) / 100;
			break;
		case 5:
		case 15:
		case 25:
			point += (p[i] * 5) / 100;
			break;
		default:
			point += p[i] / 100;
		}
	}
	printf("%d", point);
	return 0;
}*/
#include <stdio.h>

int main()
{
	char S[4];
	int i, flag = 0;

	scanf("%s", S);

	for (i = 1; i<3; i++) {
		if (S[i] == S[i - 1] )
			flag = 1;
		 if(i == 2 &&((S[i - 1] == S[i - 2])|| S[i] == S[i - 2]))
			flag = 1;
	}
	if (flag == 0) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
