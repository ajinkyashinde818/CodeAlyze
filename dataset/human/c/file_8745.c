#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n+1];
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int k,j,count=0;
    i=1;
    for(;count<n;){
        j=a[i];count++;
        if(j==2){printf("%d\n",count);return 0;}

        i=a[j];count++;
        if(i==2){printf("%d\n",count);return 0;}


    }
    printf("-1\n");
        return 0;
}
