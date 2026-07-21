#include <stdio.h>
long long n,i,j,x;
int ans=0;

int main(void){
    scanf("%lld",&n);

    for(i = 2; i * i <= n; i++){
        
        //printf("%lld ", i);
        for(x = 0; n % i == 0; x++) { // 素数がいくつあるか確認
            n /= i; 
        }
        //printf("%lld ", x);

        for(j=0; j * (j + 1) / 2 <= x; j++); // 1,2,3,....の組を見つける 
        
        //printf("%lld\n", j - 1);
        ans += j - 1;
    }

    if (n - 1) ans += 1;

    printf("%d",ans);

}
