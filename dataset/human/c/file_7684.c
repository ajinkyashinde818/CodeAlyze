#include<stdio.h>
int main(){
    int i;
    int num[10001];
    for (i=1;i<10001;i++){
        scanf("%d",&num[i]);
        if(num[i]!=0){
            printf("Case %d: %d\n",i,num[i]);
        }else{
            i=10001;
        }
    }
    return 0;
}
