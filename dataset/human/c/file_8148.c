#include <stdio.h>
#include <stdlib.h>

int main(){
    int A,B,C,D;
    scanf("%d %d %d %d",&A,&B,&C,&D);
    long first = A*B;
    long second = C*D;
    if(first>second){
        printf("%ld",first);
    }else{
        printf("%ld",second);
    }
    return 0;
}
