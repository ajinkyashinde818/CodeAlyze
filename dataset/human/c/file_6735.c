#include <stdio.h>
int stu[501][10001];
int main (void){
    int n,m,a,b,i,j;
    for(;;){
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        int sanka1[501]={0},sanka2[501]={0},ans=0;
        for(i=0;i<501;i++){
            for(j=0;j<10001;j++){
                stu[i][j]=0;
            }
        }
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            stu[a][b]=1;
        }
        for(i=0;i<=n;i++){
            if(stu[1][i]==1||stu[i][1]==1){
                sanka1[i]=1;
                sanka2[i]=1;
            }
        }
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                if(sanka1[i]==1&&(stu[i][j]==1||stu[j][i]==1)){
                    sanka2[j]=1;
                }
            }
        }
        for(i=0;i<=n;i++){
            if(sanka2[i]==1){
                ans++;
            }
        }
        if(ans!=0)ans=ans-1;
        printf("%d\n",ans);
    }
return 0;
}
