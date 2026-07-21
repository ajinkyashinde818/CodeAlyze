#include <stdio.h>

int main(void)
{
	int A,B,C;
	int cookie=0;
	
	scanf("%d%d%d",&A,&B,&C);
	
	if(B>=C){
	cookie = B+C;
	}else if(B<C){
	
		if(A>=C-B){
		cookie = B+C;
		}else if(A<C-B){
		cookie = A+(2*B);
		}
	
	}
	
	if(C>A+B){
	cookie += 1;
	}
	
	printf("%d",cookie);
	return 0;
}
