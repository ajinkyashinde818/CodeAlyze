#include <stdio.h>

int main(void)
{
	int n;
	int i;
	
	int stone;
	int man;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++){
		scanf("%d %d", &stone, &man);
		
		if (stone % man == 0){
			printf("%d\n", man);
		}
		else {
			printf("%d\n", stone % man);
		}
	}
	
	return (0);
}
