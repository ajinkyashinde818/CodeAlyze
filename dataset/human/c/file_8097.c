#include <stdio.h>

int main(void){
	int A,B,C,D;
	scanf("%d%d%d%d",&A,&B,&C,&D);

//printf ("%d%d%d%d\n",A,B,C,D);

	if(A*B>C*D)
	printf("%d\n",A*B);

	else if(A*B<C*D)
	printf("%d\n",C*D);

	else
		printf("%d\n",A*B);
return 0;

}
