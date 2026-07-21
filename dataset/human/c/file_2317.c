#include<stdio.h>
int main(){
    int n,k,s;scanf("%d %d %d",&n,&k,&s);
    int cnt=0;
    //printf(">%d\n",(int)10e1);
    for(int i=0;i<n;i++){
        if(cnt==k){
            if(s==1000000000)printf("%d ",s-1);
            else printf("%d ",s+1);
        }else{
            printf("%d ",s);
            cnt++;
        }
    }
    printf("\n");
}
