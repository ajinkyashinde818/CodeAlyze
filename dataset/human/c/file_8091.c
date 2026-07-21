#include <stdio.h>

int main()
{
	int A;
	int B;
	int C;
	int D;
	int R1;
        int R2;
	
	scanf("%d %d %d %d",&A,&B,&C,&D);
	
	R1=A*B;
	R2=C*D;
	
	if(R1>=R2)
	printf("%d\n",R1);
	else
	printf("%d\n",R2);
	
	return 0;
}
