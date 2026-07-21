#include <stdio.h>

int main()
{
	long A, B;
	scanf("%d %d", &A, &B);
	
	if(A > B){
		int temp = A;
		A = B;
		B = temp;
	}
	
	int multiple = 1;
	while(true){
		long X = A * multiple;
		if(X % B == 0){
			break;
		}
		multiple ++;
	}
	
	printf("%ld\n", A * multiple);
	
	return 0;
}
