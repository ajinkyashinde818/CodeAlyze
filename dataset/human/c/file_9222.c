#include<stdio.h>
int main(void){
    int n,k,cnt=0;
    scanf("%d%d",&n,&k);
    int h[100000];
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
        if(h[i]>=k){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
