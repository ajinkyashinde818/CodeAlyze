#include <stdio.h>

int main()
{
    int N = 0,sum = 0,d = 0,e = 0;
    scanf("%d",&N);
    int a[20],b[50],c[50];
    for(int i = 0;i < N;i++)scanf("%d",&a[i]);
    for(int l = 0;l < N;l++)scanf("%d",&b[l]);
    for(int k = 0;k < N-1;k++)scanf("%d",&c[k]);
    for(int n = 0;n < N;n++)
    {
        sum += b[n];
        d = a[n];
        if(n != 0)e = a[n-1] + 1;
        if(d == e)sum += c[a[n]-2];
    }
    printf("%d",sum);
    return 0;
}
