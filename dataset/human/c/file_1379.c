#include"stdio.h"
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int f[n+1][2];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<2;j++)
            f[i][j]=0;
    int a[m],b[m];
    for(int i=0;i<m;i++)
        scanf("%d %d",&a[i],&b[i]);

    for(int i=0;i<m;i++){
        if(a[i]==1) f[b[i]][0]=1;
        if(b[i]==n) f[a[i]][1]=1;
    }
    
    for(int i=0;i<n+1;i++)
        if(f[i+1][0]==1&&f[i+1][1]==1){
            printf("POSSIBLE\n");
            return 0;
        }

    printf("IMPOSSIBLE\n");
}
