#include <stdio.h>
int main(){
    long k,n,a[200000],b[200000],max=0;
    // char s[150];
    scanf("%ld%ld",&k,&n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%ld",&a[i]);
    }
    
    for (size_t i = 0; i < n-1; i++)
    {
        b[i] = a[i+1] - a[i];
    }
    b[n-1] = (k - a[n-1]) + a[0];
    
    for (size_t i = 0; i < n; i++)
    {
        if (max < b[i])
        {
            max = b[i];
        }
        
    }
    printf("%ld",k-max);
    
    return 0;
}
