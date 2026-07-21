#include<stdio.h>
int main(void){
    int a,b,c,d,e,f,g;
    for(e=0;;e++){
        scanf("%d%d",&a,&b);
        if(a==0&&b==0){
            break;
        }
    for(d=0;d<a;d++){
        if(d%2==1){
    for(c=0;c<b/2;c++){
        printf(".#");
    }
    if(b%2==1){
            printf(".");
        }
        }
        else if(d%2==0){
    for(c=0;c<b/2;c++){
        printf("#.");
    }
    if(b%2==1){
            printf("#");
        }
        }
    printf("\n");
    }
    printf("\n");
    }
    return 0;
}
