#include<stdio.h>                                                               
#include<stdlib.h>

int main(void){
    int N;
    scanf("%d",&N);
    int R;
    scanf("%d",&R);
    int S=0;
    if(N >= 10){
        S=R;
    }else{
        S=R+(100*(10-N));
    }
    printf("%d\n",S);

    return 0;
}
