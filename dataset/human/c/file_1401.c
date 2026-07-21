#include <stdlib.h>
#include <stdio.h>

int main()
{   int n,m;
    scanf("%d%d",&n,&m);
    int a[m],b[m];
    int f[200001]={0},s[200001]={0};
    for(int i=0;i<m;i++){
        scanf("%d%d",&a[i],&b[i]);
        if(a[i]==1){
            f[b[i]]=1;
        }
        if(b[i]==n){
            s[a[i]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(f[i]==1&&s[i]==1){
            printf("POSSIBLE");
            return 0;
        }
    }
    printf("IMPOSSIBLE");
    return 0;
}
