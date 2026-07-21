#include<stdio.h>
int main(){
    int n,a[100000],i,t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        t=a[t]-1;
        if(t==1){
            printf("%d\n",i+1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
