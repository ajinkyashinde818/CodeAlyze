#include<stdio.h>

int main(void){
    long int a,b;
    scanf("%ld %ld",&a,&b);


    long int x = a*b;
    long int tmp;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }

    tmp = a % b;
    while(tmp!=0){
        a = b;
        b = tmp;
        tmp = a % b;
    }

    printf("%ld\n",x/b);

    return 0;
}
