#include <stdio.h>
int main(void){
    int N,D,X,i,j,Y;
    scanf("%d",&N);
    scanf("%d %d",&D,&X);
    
    int A[N];
    
    for(i=1;i<=N;i++){
        scanf("%d",&A[i]);
    }
    
    Y = 0;
    
    for(i=1;i<=N;i++){
        for(j=1;j<=D;j++){
            if((j-1)%A[i] == 0){
                Y ++;
            }
        }
    }
    
    Y += X;
    
    printf("%d",Y);
}
