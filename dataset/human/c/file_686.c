#include <stdio.h>

int main(void)
{
    char a[50][50]={},b[50][50];
    int n,m,i,j,x,y,ans=1;
    
    scanf("%d %d",&n,&m);
    
    for(i=0;i<n;i++)scanf("%s",a[i]);
    for(i=0;i<m;i++)scanf("%s",b[i]);
    for(i=0;i<n-m+1;i++){
        for(j=0;j<n-m+1;j++){
            for(x=0;x<m;x++){
                for(y=0;y<m;y++){
                    if(a[i+x][j+y]!=b[x][y])ans=0;
                }
            }
            if(ans==1){
                printf("Yes\n");
                return 0;
            }
            ans=1;
        }
    }
    
    printf("No\n");

    return 0;
}
