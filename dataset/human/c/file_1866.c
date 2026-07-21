#include <stdio.h>
int main()
{
    int n,i,point=0;
    scanf("%d",&n);
    int A[n+1], B[n+1];
    int C[n];
    for(i=1;i<=n;i++)scanf("%d",&A[i]);
    for(i=1;i<=n;i++)scanf("%d",&B[i]);
    for(i=1;i<n;i++) scanf("%d",&C[i]);
    point=B[A[1]];
    for(i=2;i<=n;i++)
    {
        point+=B[A[i]];
        if(A[i]-A[i-1]==1)point+=C[A[i-1]];
    }
    printf("%d",point);
    return 0;
}
