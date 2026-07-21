#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	if(a*b>c*d){
		printf("%d\n",a*b);
	}else{
		printf("%d\n",c*d);
	}
	
    return 0;
}
