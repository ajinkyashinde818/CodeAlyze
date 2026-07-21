#include<stdio.h>
#include<stdlib.h>


int main(){
    int n,k,h,sum=0;

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&h);
        if(h>=k){
            sum++;
        }
    }
    printf("%d\n",sum);

    return 0;
}
