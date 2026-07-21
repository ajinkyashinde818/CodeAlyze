#include <stdio.h>
int main(void){
    int n,m,i,j,a[200001],b[200001],ac[200001],nc[200001];
    scanf("%d %d",&n,&m);
    for(j=0;j<m;j++){
        scanf("%d %d",&a[j],&b[j]);
    };
    for(i=1;i<=n;i++){
        ac[i]=nc[i]=0;
    };
    for(j=0;j<m;j++){
        if(a[j]==1){
            ac[b[j]]=1;
        };
        if(b[j]==1){
            ac[a[j]]=1;
        };
        if(a[j]==n){
            nc[b[j]]=1;
        };
        if(b[j]==n){
            nc[a[j]]=1;
        };
    };
    for(i=2;i<n;i++){
        if(ac[i]==1 && nc[i]==1){
            printf("POSSIBLE");
            return 0;
        }
    };
    printf("IMPOSSIBLE");
    return 0;
};
