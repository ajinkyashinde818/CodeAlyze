#include <stdio.h>
int m,n;
int a[200000],b[200000];
int i,j,k,l,max;
int main(void){
    scanf("%d %d",&k,&n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d",&a[i]); 
    }
    b[0] = k - a[n-1] + a[0];
    for (size_t i = 1; i < n; i++)
    {
        b[i] = a[i] - a[i-1];
    }
    max = b[0];
    for (size_t i = 1; i < n; i++)
    {
        if (max < b[i])
        {
            max = b[i];
        }
    }
    printf("%d\n",k - max);
    return 0;
}
