#include <stdio.h>
int main(void){
    // Your code here!
    int N,K,ans=0;
    int i,j;
    int h[100000];
    scanf("%d%d",&N,&K);
    for(i=0;i<N;i++){
        scanf("%d",&h[i]);
        if(h[i]>=K)ans++;
    }
    printf("%d\n",ans);
}
