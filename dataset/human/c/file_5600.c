#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	long long point;
	scanf("%lld",&point);
	long long move=point/11*2;
	
	if(point%11==0){
		
	}else if(point%11<=6){
		move++;
	}else{
		move+=2;
	}
	
	printf("%lld\n",move);
	
    return 0;
}
