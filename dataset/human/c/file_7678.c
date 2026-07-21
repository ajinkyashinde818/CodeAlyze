#include <stdio.h>

int main(void)
{
	
	int i = 0, no = 0;
	int array[10000] = { 0 };

	while (1) {
		scanf("%d", &array[i]);
		if (array[i] == 0) {
			break;
		}
		i++;
	}

	i = 1;
	
	while (1) {
		if (array[no] == 0) {
			break;
		}
		printf("Case %d: %d\n", i, array[no]);
		i++;
		no++;
	}

	return 0;
}
