#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	long long int A=0,B=0,q=0,r=0,temp=0,g=1,x=0;
	scanf("%d %d", &A, &B);

	if(B>A){
	 temp = A;
	 A = B;
	 B= temp;
	}

	r=A % B;
	q=B;

	switch(r){
	case 0:x=A;break;
	case 1:x=A*B/g;break;
	default:
		while(r!=1 && r !=0){
		g = r;
		r = q % r;
		q = g;
	}
		if(r!=0){
			g=r;
		}
		x=A*B/g;
	}

	printf("%lld", x);
	return 0;
}
