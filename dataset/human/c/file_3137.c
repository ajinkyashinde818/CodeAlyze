#include<stdio.h>
#include<string.h>

int main(void)
{
    int x,n;
    int ans=0;
    int max=0;
    int i;

    scanf("%d %d",&x,&n);
    // printf("%d %d",x,n);
    int  a[n];
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
        // printf("%d\n",a[i]);
    }
    // printf("%d\n",i);

    for (i=0;i<n-1;i++){
        if (a[i+1]-a[i]>max)
            max=a[i+1]-a[i];
    }

    if (a[0]+x-a[n-1]>max)
        max=a[0]+x-a[n-1];

    ans=x-max;
    printf("%d\n",ans);
    
    return 0;
}
