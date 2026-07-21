#include <stdio.h>

int main(void){
    long int A,B;
    scanf("%ld %ld",&A,&B);
    long int r;
    if (A<B) {
        int tmp;
        tmp=A;
        A=B;
        B=tmp;
    }
    r=A%B;
    long int a=A,b=B;
    while (r!=0) {
        a=b;
        b=r;
        r=a%b;
    }
    printf("%ld\n",(A*B)/b);
    return 0;
}
