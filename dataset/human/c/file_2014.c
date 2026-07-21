#include<stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = 0;
    if(b > c){
        ans = b+c;
    } else {
        ans += 2*b;
        c -= b;
        if(a >= c){
            ans += c;
        } else {
            ans += a+1;
            
        }
    }

    printf("%d\n", ans);
    return 0;
}
