#include<stdio.h>
#define SIZE 1000000001

int main(void)
{
    long min,max,a;
    int n,i;

    min=SIZE;
    max=-SIZE;
    scanf("%d",&n);
    //printf("scan n=%d\n",n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        //printf("scan %d\n",a);
        if(min!=SIZE&&a-min>max)
        {
            //printf("max=%d\n",a-min);
            max=a-min;
        }
        if(a<min)
        {
            min=a;
            //printf("min=%d\n",min);
            continue;
        }

    }

    printf("%d\n",max);

}
