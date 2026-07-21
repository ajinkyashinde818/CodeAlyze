#include <stdio.h>

int main(){
    unsigned long int a, b, r;
    unsigned long int x, tmp;

    scanf("%lu %lu", &a, &b);

    x = a * b;
     /* 自然数 a > b を確認・入替 */
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    
    /* ユークリッドの互除法 */
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }

    printf("%lu\n", x/b);

}
