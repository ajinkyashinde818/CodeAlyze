#include <stdio.h>
#include <string.h>

#define max 100

int main()
{
    int a, b, k, i, j=0, str[max];
    
    scanf("%d %d %d", &a, &b, &k);
    
    for (i=1; i<=100; i++) {
        if (a%i==0&&b%i==0) {
            str[j]=i;
            j++;
            
        }
    }
    
    printf("%d", str[j-k]);
    
    return 0;
}
