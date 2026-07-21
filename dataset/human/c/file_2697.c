#include <stdio.h>

#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int main(void){
    int k,s;
    int a,b, ans;
    
    scanf("%d%d", &k,&s);
    ans = 0;
    for (a = MAX(0, s - 2*k); a <= MIN(s, k); a++){ // range of x
        ans += b = MIN(s-a, k) - MAX(0, s - a - k) + 1; // range of y
 //       printf("%d,%d ", a,b);
    }
    printf("%d\n", ans);
    return 0;
}
