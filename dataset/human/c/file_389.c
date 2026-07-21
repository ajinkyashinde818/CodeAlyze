#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int N,R,a;
    scanf("%d%d",&N,&R);
    if (N> 10){
        printf("%d\n",R);
    } 
    else{
        printf("%d\n",(R + 100*(10-N)));
    }

    return 0;
}
