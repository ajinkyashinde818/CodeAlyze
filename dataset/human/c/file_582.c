#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<stack>
#include<vector>


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char a[n+1][n+1],b[m+1][m+1];
    int i,j,si,sj;
    for(i=0;i<=n-1;i++)scanf("%s",a[i]);
    for(i=0;i<=m-1;i++)scanf("%s",b[i]);
    
    int ans=0;
    
    for(si=0;si<=n-m;si++)for(sj=0;sj<=n-m;sj++){
        int flag=0;
        for(i=si;i<=si+m-1;i++)for(j=sj;j<=sj+m-1;j++){
            if(a[i][j]!=b[i-si][j-sj])flag=1;
        }
        if(flag==0)ans=1;
    }
    
        if(ans==0)printf("No");
        else printf("Yes");
    
    return 0;
}
