#include<stdio.h>
int main ()
{
    int n,d,x,z,i,a[200],q,j;
    scanf("%d%d%d",&n,&d,&x);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        q=a[i];
        for(j=1;j<=d;j+=q)
        {
            x++;
        }
    }
    printf("%d\n",x);
}
