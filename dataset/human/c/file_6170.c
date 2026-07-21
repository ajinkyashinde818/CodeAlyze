#include<stdio.h>
int main()
{
    int values[200000],min,max;
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&values[i]);
    }
    max=values[1]-values[0];
    min=values[0];
    for(i=1;i<n;i++)
    {
        max=max>values[i]-min?max:values[i]-min;
		min=min<values[i]?min:values[i];
    }
    printf("%d\n",max);
}
