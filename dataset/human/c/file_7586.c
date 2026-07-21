#include <stdio.h>
#define I 10000
int main(void)
{
    int i, j, x[I];
    i = 0;
    while(1) {
        scanf("%d", &x[i]);
        if(x[i]==0)
            break;
        i++;
        j = i;
    }
         
         
         
         
    for(i = 0; i < j; i++) {
        printf("Case %d: %d\n", i+1, x[i]);
    }
    
    return 0;
}
