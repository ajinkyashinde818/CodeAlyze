#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long k, n;
    long long *a;
    long long max = 0;
    long long before, after;
    long long start;
    
    scanf("%lld %lld", &k, &n);
    
    a = (long long*)malloc(sizeof(long long));

    before = 0;
  
    for(int i=0;i<n;i++){
        scanf("%lld ",&after);
        if(i==0){
            start = after;
        }
        if(max < (after - before)){
            max = after - before;
        }
        before = after;
    }
    
    if(max < start + k - after){
        max = start + k - after;
    }
    
    printf("%lld", k - max);
    

    return 0;
  
}
