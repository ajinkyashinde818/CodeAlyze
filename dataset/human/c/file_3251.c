#include<stdio.h>
#include<stdlib.h>

int main(){
    int K,N;
    scanf("%d",&K);
    scanf("%d",&N);
    int a[K];
    int i;
    for(i=0;i<N;i++){
       scanf("%d",&a[i]);
    }
    int min= a[N-1]-a[0];
    for(int j=1;j<N;j++){
        if((K-a[j]+a[j-1])<min){
            min = (K-a[j]+a[j-1]);
        }
    }
    for(int k=0;k<N-1;k++){
        if((K-a[k+1]+a[k])<min){
            min = (K-a[k+1]+a[k]);
        }
    }
    printf("%d",min);

    return 0;

}
