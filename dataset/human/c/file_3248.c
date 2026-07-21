#include<stdio.h>
int main(void)
{
    int k,n,i,a[200001],max=0,temp;
    scanf("%d %d",&n,&k);
    for(i=0;i<k;i++) {
        scanf("%d", &a[i]);
        if(i>0&&a[i]-a[i-1]>max)
            max=a[i]-a[i-1];
    }
    temp=a[0]+n-a[k-1];
    if(temp>max)
        max=temp;
    printf("%d",n-max);
    return 0;
}
