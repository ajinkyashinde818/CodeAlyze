#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    long long int all=0,x=0,min=1000000000000000000,temp;
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        all+=a[i];
    }
    for(int i=0;i<n-1;i++){
        x+=a[i];
        temp=all-2*x;
        temp=temp>0?temp:-temp;
        min=min>temp?temp:min;
    }
    printf("%lld\n",min);
    return 0;
}
