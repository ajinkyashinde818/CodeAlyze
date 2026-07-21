#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n,i,a[200000];
    long int sumx=0,sumtotal=0,dif,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    };
    for(i=0;i<n;i++){
        sumtotal+=a[i];
    };
    //printf("sumtotal=%d\n",sumtotal);
    sumx=a[0];
    ans=dif=labs(sumtotal-sumx-sumx);
    //printf("dif=%d\n",dif);
    for(i=1;i<n-1;i++){
        sumx+=a[i];
        dif=labs(sumtotal-sumx-sumx);    
        //printf("dif=%d\n",dif);
        if(dif<ans){
            ans=dif;
        };
    };
    printf("%ld",ans);
    return 0;
};
