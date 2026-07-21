#include <stdio.h>

int main(void)
{
    
    int i,n,t,count=0;
    static int a[100001]={0};
    
    scanf("%d",&n);
    
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    
    t=1;
    for(i=0;i<=n;i++){
        count++;
        if(a[t]==2){
            printf("%d\n",count);
            count=0;
            break;
        }
        t=a[t];
    }
    
    if(count!=0)printf("-1\n");
    
    return 0;
}
