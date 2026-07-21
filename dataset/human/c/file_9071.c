#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    int N,K,ans=0;
    scanf("%d" "%d",&N,&K);
    int h[100010];
    for(int i = 0; i < N; i++){
        scanf("%d",&h[i]);
        if(h[i]>=K)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
