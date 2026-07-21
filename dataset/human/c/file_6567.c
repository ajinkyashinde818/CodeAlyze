#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    
    int R[n];
    
    for(int i=0;i<n;i++)
        scanf("%d",&R[i]);
    
    int max,min;
    max=R[1]-R[0];
    min=R[0];
    for(int i=1;i<n;i++)
    {
        if(max<R[i]-min)max=R[i]-min;
        if(min>R[i])min=R[i];
    }
    
    printf("%d\n",max);
    return 0;
}
