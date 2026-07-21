#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int rate;
	scanf("%d",&rate);
	if(rate<1200){
		puts("ABC");
	}else{
		puts("ARC");
	}
	
    return 0;
}
