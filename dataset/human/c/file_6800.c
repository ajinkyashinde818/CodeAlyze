#include <stdio.h>
#include <stdlib.h>
int compare(const void*a,const void*b){
    if(*(int *)a>*(int *)b)return 1;
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    long a[3*n];
    for(int i=0;i<3*n;i++)
    scanf("%ld",&a[i]);
    qsort(a,3*n,sizeof(long),compare);
    long ans=0;
    for(int i=3*n-1;i>n-1;i-=2){
        ans+=a[i-1];
    }
    printf("%ld",ans);
    return 0;
}
