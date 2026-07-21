#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int N;//人数
    int D;//日数
    int X;//残っていたチョコレート
    
    int *A;
    int i,j;
    scanf("%d",&N);
    scanf("%d%d",&D,&X);
    
    A = (int*)malloc(sizeof(int)*N);
    if(A == NULL)exit(0);
    
    
    for(i = 0;i<N;i++){
        scanf("%d",&A[i]);
    }
    //
    
    int Max;//チョコレートの合計値
    Max = X;
    
    int x;//kosuu
    x = 0;
    for(j=0;j<N;j++){
        for(i=0;i<D;i++){
            
            
            if((i+1) == x*A[j]+1){
                Max += 1;
                x += 1;
            }
            
        }
        x = 0;
    }
    
    
    
    printf("%d",Max);
    
    
    
    free(A);
    return EXIT_SUCCESS;
}
