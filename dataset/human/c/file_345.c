#include <stdio.h>

int main(void){
        int num,num1,num3;
        scanf("%d %d",&num,&num1);
        if(num<11){
                num3=100*(10-num);
                num3=num1+num3;
                printf("%d",num3);
        }else{
                printf("%d",num1);
        }       
    return 0;
}
