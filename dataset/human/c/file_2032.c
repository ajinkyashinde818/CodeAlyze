#include <stdio.h>


int main(){
	int A,B,C;
	scanf("%d %d %d",&A,&B,&C);
	
	if(A+B >= C){
		printf("%d\n",B+C);
	}else{
		printf("%d\n",A+2*B+1);
	}
	return 0;
}

int Mymin(int a,int b){
	int r;
	if(a < b){
		r = a;
	}else{
		r = b;
	}
	return r;
}
