#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int n, i;
	
	while(1){
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		
		for(i = 0; n != 1; i++){
			if(n%2 == 0){
				n /= 2;
			} else {
				n = 3*n+1;
			}
		}
		printf("%d\n", i);
	}
	return 0;
}
