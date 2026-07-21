#include<stdio.h>

int main(){
	
	char buf[256];
	int A, B, C, D;
	int S1, S2;
		
	fgets(buf,256,stdin);
	sscanf(buf,"%d %d %d %d",&A, &B, &C, &D);
	
	S1 = A*B;
	S2 = C*D;
	
	printf("%d\n", ((S1 >= S2) ? S1 : S2));
	return 0;
}
