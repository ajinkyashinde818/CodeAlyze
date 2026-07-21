#include <stdio.h>

int main(void){
	int mem, day, x, choco = 0;

	scanf("%d", &mem);
	scanf("%d", &day);
	scanf("%d", &x);

	int a[mem];

	for (int i = 0; i < mem; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < mem; i++)
	{
		for (int j = 1; j < day + 1; j += a[i])
		{
			choco++;
		}
	}

	printf("%d\n", choco+x);

	return 0;
}
