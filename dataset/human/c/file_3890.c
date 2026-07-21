#include <stdio.h>

int main(void)
{
	int a, b, k, tmp;
	int yaku[100];
	int yakunum=0;

	if(scanf("%d %d %d", &a, &b, &k) == EOF) return 0;


	if (b > a) {
		tmp = a;
		a = b;
		b = tmp;
	}

	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			yaku[yakunum] = i;
			yakunum++;
		}
	}

	printf("%d\n", yaku[yakunum - k]);

	return 0;
}
