#include<stdio.h>
#include<string.h>
int main(void){
    int n,m;
    int e[100001]={0}, idx[200001]={0};
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&e[i]);
        idx[e[i]]=1;
    }
    //puts("");
    for(int i=m;i>0;i--){
        if(idx[e[i]]==1){
            idx[e[i]]=-1;
            printf("%d\n",e[i]);
        }
    }
    //puts("");
    for(int i=1;i<=n;i++){
        if(idx[i]==0){
            printf("%d\n",i);
        }
    }
    return 0;
}
