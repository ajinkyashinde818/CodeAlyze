#include <stdio.h>

int main(){
    int A,B,K ;
    int i,cnt,small;
    int a[101]={};
    int ans=0;
    cnt=0;
    
    scanf("%d %d %d",&A,&B,&K);
    if(A>B) small=B;
    else small=A;
    for(i=1;i<=small;i++){
        if(A%i==0 && B%i==0){
            cnt++;
            a[cnt]=i;
            // if(cnt==K) ans = i;
        }
    }
    //printf("%d\n",cnt);
    //for(i=0;i<=small;i++){
    //    printf("%d\n",a[i]);
    //}
    printf("%d\n",a[cnt-K+1]);

}
