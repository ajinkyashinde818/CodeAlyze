#include <stdio.h>
int min(int a,int b);
int max(int a,int b);
int main(){
    int a=0,i,k=0,n,t;
    scanf("%d",&n);
    scanf("%d",&a);
    for(i=1;i<n;i++){
        scanf("%d",&k);
        if(i==1)
        t=k-a;
        else{
            t=max(t,(k-a));
        }
        a=min(a,k);
    }
    printf("%d\n",t);
    return 0;
}
int min(int a,int b){
    if(a>b)
    return b;
    else
    return a;
}
int max(int a,int b){
    if(a>b)
    return a;
    else
    return b;
}
