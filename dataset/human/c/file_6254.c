#include <stdio.h>
int main(
){
    int a,b,c,i,min=0,profit=0;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    profit = c-b;
    if(c<b){
        min=c;
    } else{
        min=b;
    }
    
    for(i=2;i<a;i++){
        scanf("%d",&b);
        if(profit < b - min){
            profit = b - min;
	}
        if(min > b){
            min = b;
	}
    } 
    printf("%d\n",profit);
    return 0;
}
