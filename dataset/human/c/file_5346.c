#include <stdio.h>
#include <math.h>

int main(void){
    int N,M,X;
    int C[12];
    int A[12][12];
    int min = 1000000000;
    int ans = -1;
    
    scanf("%d%d%d",&N,&M,&X);
    
    for(int i = 0; i < N; i++){
        scanf("%d",&C[i]);
        for(int j = 0; j < M; j++){
            scanf("%d",&A[i][j]);
        }
    }
    
    for(int i = 1; i < (int)pow(2,N); i++){
        int und[12] = {};
        int sum = 0;
        
        for(int j = 0; j < N; j++){
            if((i >> j & 1) == 1){
                sum += C[j];
                for(int z = 0; z < M; z++){
                    und[z] += A[j][z];
                }
            }
        }
        
        int flag = 1;
        for(int j = 0; j < M; j++){
            if(und[j] < X){
                flag = 0;
                break;
            }
        }
        
        if(flag == 1 && min > sum){
            min = sum;
            ans = i;
        }
    }
    
    if(ans == -1){
        printf("-1\n");
    }
    else{
        printf("%d\n",min);
    }
}
