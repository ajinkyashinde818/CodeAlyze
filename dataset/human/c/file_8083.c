#include<stdio.h>
int main(){
	int A, B, C, D, AB,CD,HK;
	scanf("%d %d %d %d",&A,&B,&C,&D);
	AB = A*B;CD = C*D;
	if (AB == CD){
		HK = CD;
	}
	else if(AB<CD){
		HK = CD;
	}
	else{
		HK = AB;
	}

	printf("%d\n",HK);
	return 0;
}
