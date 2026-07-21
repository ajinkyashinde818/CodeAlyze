#include <stdio.h>

int inc(int a,int o,int C,int d){
	while(d>=(a+1)){
		C = C+1;
		a = a+o;
	}
	return C;
}

int main(){
	int N,d,x,a,o,C,i;
	scanf("%d",&N);
	scanf("%d %d",&d,&x); 
	C = N;
	for(i= 0; i<N ;i++){
		scanf("%d",&a);
		C = inc(a,a,C,d);
	}
	C=C+x;
	printf("%d",C);
}
