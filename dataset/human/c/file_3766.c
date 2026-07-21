#include <stdio.h>

int main(void) {
	long long a, b, temp, r,x;
	scanf("%d %d", &a, &b);
	x = a * b;
	if(b>a){
		temp = a;
		a = b;
		b = temp;
	}
	while((r=a%b)!=0){
    	a=b;
    	b=r;
    }
	printf("%ld\n", x / b);

	return 0;    
}
