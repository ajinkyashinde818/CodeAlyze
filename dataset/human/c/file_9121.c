#include <stdio.h>
int main(void){
    // Your code here!
    int N,K;
    int h[100001];
    scanf("%d %d\n",&N,&K);
    int i,ct;
    ct=0;
    for(i=1;N>=i;i++){
        scanf("%d",&h[i]);
        if(h[i]>=K) ct++;
    }
    
    printf("%d\n",ct);
}
