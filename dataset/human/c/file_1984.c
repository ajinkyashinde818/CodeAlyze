#include<stdio.h>
int main(void){
    int a, b, c, poi = 1, count =0;
    if(scanf("%d %d %d", &a, &b, &c) ==1){};
    
    while(1){
	
	if (c>0){
	    count +=1;
	    c-= 1;
	    poi = 0;
	}
	if(b>0){
	    count +=1;
	    b -= 1;
	    poi = 1;
	}
	else if (a>0 && poi ==0){
	    a -= 1;
	    poi = 1;
	}
	else {
	    if (poi==1 && c>0) count +=1;
	    break;
	}
    }
    printf("%d\n", count);
    return 0;
}
