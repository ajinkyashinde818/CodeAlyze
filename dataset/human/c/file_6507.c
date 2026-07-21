#include<stdio.h>

int main(void){
    int N;
    scanf("%d",&N);
    int R[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&R[i]);
    }    
    int max = R[1]-R[0];
    int min = R[0];
    for(int i = 1; i < N; i++){
        if(max < R[i]-min){
            max = R[i]-min;
        }
        if(min > R[i]){
            min = R[i];
        }
    }
    printf("%d\n",max);
    return 0;
}
