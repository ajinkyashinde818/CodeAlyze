#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    int K,S;
    scanf("%d %d",&K,&S);
    int ans=0;
    for(int i=0;i<=K && i<=S;i++){
        for(int j=0;j<=K && i+j<=S;j++){
            if(S-i-j>=0 && S-i-j<=K) ans++;
        }
    }
    printf("%d",ans);
}
