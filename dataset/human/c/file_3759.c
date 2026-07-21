#include<stdio.h>
int main()
{
    int i;
    int a, b;
    long ans = 1;
    scanf("%d%d", &a, &b);
    i = 2;
    while(1){
        if(a % i == 0 || b % i == 0){
            if(a % i == 0) a /= i;
            if(b % i == 0) b /= i;
            ans *= i;
        }else{
            i++;
        }
        if(a == 1 && b == 1) break;
    }
    printf("%ld\n", ans);
    return 0;
}
