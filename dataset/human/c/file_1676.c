#include <stdio.h>

int main()
{
    int n;
    int i;
    int num;
    int manzoku=0;
    int prev=100;
    scanf("%d",&n);

    int a[n];
    int b[n];
    int c[n-1];

    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        a[i]=num;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        b[i]=num;
    }
    for(i=0;i<n-1;i++)
    {
        scanf("%d",&num);
        c[i]=num;
    }

    for(i=0;i<n;i++)
    {
        manzoku+=b[a[i]-1];
        if(a[i]-prev==1)
        {
            manzoku+=c[a[i]-2];
        }
        prev=a[i];

    }

    printf("%d\n",manzoku);

    return 0;
}
