#include<stdio.h>
int main(){
    int n,d,x;
    scanf("%d%d%d",&n,&d,&x);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        x+=d/a[i];
        if(d%a[i]>0){
            x+=1;
        }
    }
    printf("%d\n",x);
    return 0;
}
