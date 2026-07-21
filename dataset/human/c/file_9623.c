#include <stdio.h>
int main(void){
    int n,m,win[1000],i,j,sum=0,k;
    char a[1000][9],b[9];
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0)break;
        for(i=0;i<n;i++){
            scanf("%s%d",a[i],&win[i]);
            a[i][8]=0;
        }
        
        sum=0;
        for(k=0;k<m;k++){
            scanf("%s",b);
            for(i=0;i<n;i++){
                for(j=7;j>=0;j--){
                    if(a[i][j]=='*'){
                        sum+=win[i];
                        break;
                    }
                    if(a[i][j]!=b[j])
                        break;
                    else if(j==0)
                        sum+=win[i];
                }
            }
        }
        printf("%d\n",sum);
    }
    
    
    return 0;
}
