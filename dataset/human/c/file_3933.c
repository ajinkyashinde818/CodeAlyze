#include<stdio.h>

int main()
{
	int A,B,K,num;
	scanf("%d %d %d",&A,&B,&K);
	if ( A > B ){
		num = B;
	} else {
		num = A;
	}

	while(1) {
		if ( ( A % num == 0 ) && ( B % num == 0 ) ) {
			K--;
		}
		if ( K == 0 ) break;
		num--;
	}

	printf("%d\n",num);
	return 0;
}
