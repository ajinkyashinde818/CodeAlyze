#include <stdio.h>
#define N 200000
int main()
{
    int max,min,n,i,a[N];
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    min=a[0];
    max=-100000000000;
    for (i=1;i<n;i++){
            if (max<a[i]-min)max=a[i]-min;
            if (min>a[i])min=a[i];
        }   
    printf("%d\n",max); 
    return 0;
}
