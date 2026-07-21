//print test cases

#include<stdio.h>

int main(void)
{
    int i=0,a[10000]={0};
    
    do
    {
        scanf("%d",&a[i]);
    }
    while (a[i++]!=0);

    i=0;

    do
    {
        printf("Case %d: %d\n",i+1,a[i]);
        i++;
    }
    while(a[i]!=0);

    return 0;

}
