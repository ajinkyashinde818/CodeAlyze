#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
int main(void){
 
	int a,b,c;
	int h;
	int p;

	scanf("%d %d %d",&a,&b,&c);

	h = a + b;

	if(h + 1 >= c){
		p = c;
	}
	else{
		p = h + 1;
	}
	
	printf("%d\n",p + b);


	return 0;
}
