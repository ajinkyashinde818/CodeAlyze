#include"stdio.h"
int main()
{
    int n;
    int p;
    int i,j;
    int max;
    int min;
    int nextmin;
    scanf("%d",&n);
    scanf("%d",&min);
    scanf("%d",&p);
    max=p-min;
    if(min>p)min=p;
    for(i=2;i<n;i++)
    {
        scanf("%d",&p);
        if(min>p)
        {
            min=p;
        }
        else if(max<p-min)max=p-min;
    }
    printf("%d\n",max);
    return 0;
}
