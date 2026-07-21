#include<stdio.h>
int main(){
    int i,a[10000];
    for(i=1;;i+=1){
        scanf("%d",&a[i]);
        if(a[i]==0){
            break;
        }
    }
    for(i=1;;i+=1){
        if(a[i]==0){
            break;
        }
        printf("Case %d: %d\n",i,a[i]);
    }
    return 0;
}
