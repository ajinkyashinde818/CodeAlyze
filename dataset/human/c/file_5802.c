#include<stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int min;
    int max;
    min=a[0];
    max = a[1]-min;
    for(int i=1;i<n;i++)
    {
        if(max<a[i]-min)
        {
            max = a[i]-min;
        }
        if(min>a[i])
        {
            min=a[i];
        }
    }
    printf("%d\n",max);
    return 0;
}
