#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int min(int A,int B){
    return A<B?A:B;
}

int main(void){
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);
    for (int i=min(a,b); i>=1; i--){
        if (a%i==0 && b%i==0){
            k--;
        }
        if (k==0){
            printf("%d\n",i);
            break;
        }
    }
    return 0 ;
}
