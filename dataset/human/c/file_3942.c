#include <stdio.h>

int main(void){

  int a,b,k;
  scanf("%d %d %d", &a, &b, &k);

	int divisors = 0;
  for (int i = 100; i > 0; i--) {
  	if (a%i == 0 && b%i == 0) {
  		divisors++;
  	}
		if (divisors == k) {
			printf("%d\n", i);
			break;
		}
  }

  return 0;
}
