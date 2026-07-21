#include <stdio.h>
#define FOR(n) for(int i=0;i<n;i++)
int main(void){
    int k,s;
    int ans=0;
    scanf("%d %d",&k,&s);
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            int p=s-i-j;
            if(p>=0&&p<=k) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
