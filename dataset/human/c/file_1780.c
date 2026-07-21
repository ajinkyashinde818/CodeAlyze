#include <stdio.h>
int main(void){
    int n,a[20],b[20],c[19],g=0,i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    scanf("%d", &a[i]);
    for(i=0; i<n; i++)
    scanf("%d", &b[i]);
    for(i=0; i<n-1; i++)
    scanf("%d", &c[i]);
    for(i=0; i<n; i++)
    {
        g+=b[i];
        if(i>0&&a[i-1]+1==a[i])
        g+=c[a[i-1]-1];
    }
    printf("%d\n", g);
    
    return 0;
}
