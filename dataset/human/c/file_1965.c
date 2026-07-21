#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,sum=0;
    int a[30],b[30],c[30];

    scanf("%d",&n);

    for(i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(i=1;i<=n;i++){
        scanf("%d",b+i);
    }
    for(i=1;i<=n-1;i++){
        scanf("%d",c+i);
    }

    for(i=1;i<=n;i++){
        sum+=b[a[i]];
        if(a[i-1]==a[i]-1){
            sum+=c[a[i-1]];
        }
    }
    printf("%d\n",sum);

    return 0;
}
