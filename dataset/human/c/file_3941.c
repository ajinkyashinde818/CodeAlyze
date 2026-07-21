#include <stdio.h>

int main(void)
{
    
    int a, b, c, k = 0, r, tmp, cnt=0;
    
    scanf("%d%d%d", &a, &b, &c);
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
    
    /* 最大公約数を出力 */
    //printf("最大公約数 = %d\n", b);
    
    
    int i;
    
    
    for( i=1; i<=b; ++i ){
        if( b%i == 0 ){
            cnt++;
        }
    }
    /* 約数を求める */
    for( i=1; i<=b; ++i ){
        if( b%i == 0 ){
            if(k==cnt-c){
                //printf("k = %d\n", k);
                //printf("cnt = %d\n", cnt);
                printf("%d\n", i);
            }
            k++;
        }
    }
    return 0;
}
