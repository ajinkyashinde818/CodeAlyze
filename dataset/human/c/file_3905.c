#include <stdio.h>
int main(void){
	int a,b,c, i , x,n,y=0;
	scanf("%d %d %d", &a,&b,&c);
	if (a < b){
		n = a;
		a = b;
		b = n;
	}
		
	for (i = a; 1 <= i; i=i-1){
		if (a%i == 0 && b%i == 0){
			x = i;
			y++;
			if (y == c)
				break;
		}
	}
	printf("%d\n", x);
	return 0;
}
