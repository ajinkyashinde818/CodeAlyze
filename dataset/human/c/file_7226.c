#include<stdio.h>
int main(void)
{
    int a,b,c,d;
    for(;;){
        scanf("%d%d",&a,&b);
        if(a == 0 && b == 0){
            break;
        }
        for(c = 0; c < a; c++){
            for(d = 0; d < b; d++){
                if((c%2 == 0 && d%2 == 0)||(c%2 == 1 && d%2 == 1)){
                    printf("#");
                }else {
                printf(".");}
            }printf("\n");
        }printf("\n");
    }
    return 0;
}
