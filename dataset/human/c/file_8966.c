#include <stdio.h>

int main(void){
	int num, count = 0;
	while (1){
		scanf("%d", &num);
		if (num == 0) break;
		while (num != 1){
			if (num%2 == 0){
				num = num/2;
				count++;
			}else{
				num = num * 3 + 1;
				count++;
			}
		}
		printf("%d\n", count);
		count = 0;
	}
	return 0;
}
