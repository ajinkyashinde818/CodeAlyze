#include <stdio.h>

int main()
{
	int sequence[20], points[19], dishes, i, temp, ans = 0;
	
	scanf("%d", &dishes);
	for(i = 0; i < dishes; i++)
		scanf("%d", &sequence[i]);
	
	for(i = 0; i < dishes; i++) {
		scanf("%d", &temp);
		ans = ans + temp;
	}
	
	for(i = 0; i < dishes - 1; i++)
		scanf("%d", &points[i]);	
	
	for(i = 0; i < dishes - 1; i++){
		if (sequence[i + 1] == (sequence[i] + 1))
			ans = ans + points[sequence[i] - 1];
	}
	
	printf("%d\n", ans);	
	
	return 0;
}
