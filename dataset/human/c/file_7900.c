#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int nd(uint64_t x)
{
    int d;
    for(d=0;x%2==0;x/=2,d++);
    return d;
}

uint64_t gcd(uint64_t x, uint64_t y)
{
    uint64_t z;
    while(y != 0){
        z = x % y;
        x = y;
        y = z;
    }
    return x;
}

int main()
{
    int N, M, a;
    scanf("%d%d", &N, &M);
    scanf("%d", &a);

    int d = nd(a);
    if(d==0){
        printf("%d\n", 0);
        return 0;
    }
    uint64_t h = a/2;
    for(int ni=1; ni<N; ni++){
        int an;
        scanf("%d", &an);
        if(d != nd(an)){
            printf("%d\n", 0);
            return 0;
        }
        h *= (an/2) / gcd(h, (an/2));
    }

    printf("%"PRIu64,  M/h - M/(2*h));
    
    return 0;
}
