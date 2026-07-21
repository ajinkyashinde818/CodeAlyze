#include <stdio.h>

int main(void){
    
  int n, x;

	long int max = -1000000000;
	long int min ;
	int i = 1;
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &x);
		if (i == 1) {
			min = x;
			
		}
		if (i != 1) {
				if (max < x - min) {
					max = x - min;
				}
				if (min > x) {
					min = x;
				}
			
		}
		i++;
	}

    printf("%d\n",max);
    return 0;
}
