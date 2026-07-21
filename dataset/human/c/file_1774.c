#include<stdio.h>
int main()
{
    int i, n, j, satisfaction = 0;
    scanf("%d",&n);
    int A[n], B[n], C[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&B[i]);
    }
    for(i=0;i<n-1;i++)
    {
        scanf("%d",&C[i]);
    }
    for(i=0;i<n;i++)
    {
        satisfaction += B[A[i]-1];
        if(i>0)
        if(A[i]-A[i-1]==1)
        {
            satisfaction += C[A[i-1]-1];
        }
    }
    printf("%d",satisfaction);
    return 0;
}
