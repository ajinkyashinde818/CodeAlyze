#include<stdio.h>
#define MAX 200000
int main()
{
    long int r[MAX], minv, maxv;
    int n, i, temp;

    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%ld", &r[i]);

    minv=r[0];
    maxv=r[1]-r[0];

    for(i=1;i<n;i++)
    {
        temp=r[i]-minv;
        if(temp>maxv) maxv=temp;
        if(r[i]<minv) minv=r[i];
    }

    printf("%d\n", maxv);

    return 0;
}
