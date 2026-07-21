#include <stdio.h>

int main(void)
{
    int test[10000];
    int i, j;
    
    do{
        scanf("%d", &test[i]);
        i++;
    }while(test[i-1]);
    
    i--;
    
    for(j=0; j<i; j++){
        printf("Case %d: %d\n", j+1, test[j]);
    }
    
    return 0;
}
