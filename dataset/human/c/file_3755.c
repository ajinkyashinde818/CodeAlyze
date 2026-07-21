#include <stdio.h>
int gcd(int x,int y){
    if (x < y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    while (y > 0) {
        int tmp = x;
        x = y;
        y = tmp % y;
    }
    return x;
}

long lcm(int a,int b){
    return (long) a * b / gcd(a,b);
}

int main(void){
    int A,B;
    scanf("%d %d",&A,&B);

    long ans = lcm(A,B);
    printf("%ld\n",ans);

    return 0;
}
