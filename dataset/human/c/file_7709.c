#include <stdio.h>

int main(){

    int i=0;
    int x[10000];


    do{
        scanf("%d",&x[i]);
        
        if(x[i] == 0){
            break;
        }

        i++;

    }while(i < 10000);

    i = 0;
    do{
        if(x[i] != 0){
            printf("Case %d: %d\n",i+1,x[i]);
        }else{
            break;
        }

        i++;

    }while(i < 10000);

    return 0;
}
