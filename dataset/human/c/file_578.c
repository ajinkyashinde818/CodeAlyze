#include <stdio.h>
 
int main(void){
    // Your code here!
    int N,M;
    char A[50][51],B[50][51];
    char *pstr;
    
    scanf("%d%d",&N,&M);
    
    for(int i = 0;i<N;i++){
        scanf("%50s",A[i]);
    }
    
    for(int i = 0;i<M;i++){
        scanf("%50s",B[i]);
    }
    
    for(int i = 0; i < N - M + 1 ;i++){
        for(int j = 0; j < N - M +1;j++){
            int flag = 0;
            for(int z = 0; z < M; z++){
                for(int k = 0; k < M;k++){
                    if(A[i+z][j+k] != B[z][k]){
                        flag = -1;
                        break;
                    }
                }
            }
            
            if(flag == 0){
                printf("Yes\n");
                return 0;
            }
        }
    }
    
    printf("No\n");
    return 0;
}
