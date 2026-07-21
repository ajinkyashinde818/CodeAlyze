#include<stdio.h>
int main()
{
    int x,i=0,n=0,a[10000];
    while(1){
        scanf("%d",&a[i]);
        if(a[i]==0){
            break;
        }
        i++;
        n++;
    }
    for(i=0;i<n;i++){
        printf("Case %d: %d\n",i+1,a[i]);
    }
    return 0;
}
