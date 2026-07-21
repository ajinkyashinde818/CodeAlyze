#include<stdio.h>
#include <math.h> 
int main(){
    int n,k;
    int h[100000];
    scanf("%d %d",&n,&k);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    int count =0;
    for(i=1;i<=n;i++){
        if(h[i]>=k){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
