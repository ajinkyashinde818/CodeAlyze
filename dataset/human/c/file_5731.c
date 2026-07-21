#include <stdio.h>

int main()
{

	int buy, sell,max;

	int n;
	scanf("%d", &n);
	
	scanf("%d", &buy);
	scanf("%d", &sell);
	
	max = sell - buy;
	if (sell < buy)
		buy = sell;

	int tmp;
	for (int i = 2; i < n; i++) {
		scanf("%d", &tmp);
		if ((tmp - buy) > max)
			max = tmp - buy;
		else if(tmp < buy)
			buy = tmp;
	}

	printf("%d\n", max);

	return 0;
}
