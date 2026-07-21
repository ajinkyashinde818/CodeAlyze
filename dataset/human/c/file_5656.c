#include<stdio.h>


int main(void){

	long x;
	long count;
	int a;
	scanf("%ld",&x);

	count = (x/11)*2;
	a = x%11;

	if(a>0 && a<=6){
		count++;
	}else if(a>6 && a<=11){
		count +=2;
	}else if(a==0){
	}



printf("%ld\n",count);
}
