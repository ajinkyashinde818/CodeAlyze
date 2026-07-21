#include<stdio.h>
int a[200000];
int main(void){
    int i,j,k,input,count=0,Count;
    for(i=2;i<=200000;i++){
        if(a[i]==0){
            count=count+i;
            a[i]=count;
            for(j=2;i*j<=200000;j++){
                a[i*j]=-1;
            }
        }
    }
    while(1){
        scanf("%d",&input);
        if(input==0)break;
        Count=0;
        for(i=2;i<200000;i++){
            if(a[i]!=-1)Count++;
            if(Count==input){
                printf("%d\n",a[i]);
                break;
            }
        }
    }
    return 0;
}
