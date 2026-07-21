#include<stdio.h>
int main(){
    int n,k;
    int count=0;
    scanf("%d %d",&n,&k);
    int h[n];
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
        if(h[i]>=k) count++;
    }
    printf("%d\n",count);

    return 0;
}
