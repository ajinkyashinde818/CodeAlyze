#include <stdio.h>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
int main(void){
    char c[1002];
    int fr[2][1000],n,i,j,x,ans,k=0;

    while(scanf("%d",&n)){
        if(n==0)break;
        ans=0;
        for(i=0;i<n;i++){
            scanf("%s",c);
            for(j=0;j<n;j++){
                if(c[j]=='.'){
                    if(i==0 || j==0)fr[!k][j]=1;
                    else {
                        x=MIN(MIN(fr[!k][j-1],fr[k][j]),fr[k][j-1])+1;
                        if(ans<x)ans=x;
                        fr[!k][j]=x;
                    }
                }
                else fr[!k][j]=0;
            }
			k=!k;
        }
        printf("%d\n",ans);
    }
    return 0;
}
