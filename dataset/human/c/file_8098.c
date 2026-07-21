#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	if(a*b<c*d)printf("%d\n",c*d);
	else printf("%d\n",a*b);
	
}
