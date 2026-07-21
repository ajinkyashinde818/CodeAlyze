#include<stdio.h>
int main(void){
    while(1){
        int n,m,i,j,a,b,count=0,cou[500]={0},pro[500][500]={0};
        scanf("%d",&n);
        scanf("%d",&m);
        if(n==0&&m==0)break;
        for(i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            pro[a-1][b-1]=1;
            pro[b-1][a-1]=1;
        }
        for(i=0;i<n;i++){
            if(pro[0][i]==1){
                cou[i]=1;
                for(j=0;j<n;j++){
                    if(pro[i][j]==1){
                        cou[j]=1;
                    }
                }
            }
        }
        for(i=1;i<n;i++){
            if(cou[i]==1){
                count++;
            }
        }
        printf("%d\n",count);
    }
return 0;
}
