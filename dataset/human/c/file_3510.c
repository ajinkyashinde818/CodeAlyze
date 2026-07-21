#include <stdio.h>
int main(void){
    long long int c = 1, i, n, a[200005] = {0}, b[200005] = {0}, d[200005], e = 0, k, num, count = 0;
    
    scanf("%lld %lld", &n, &k);
    
    for( i = 1; i <= n; i++ ){
        scanf("%lld", &a[i]);
    }
    
    b[1] = 1;
    
    for( i = 1; i != 0; i++ ){
        c = a[c];
        b[c] += 1;
        k--;
        
        if( b[c] == 2 ){
            d[e] = c;
            e++;
            count++;
        }
        
        if( b[c] == 3 ){
            break;
        }
        
        if( k <= 0 ){
            printf("%lld", c);
            return 0;
        }
        
        
 
    }
    
    num = k % count;
    
    printf("%lld\n", d[num]);
        
    return 0;
}
