#include <stdio.h>

int main(void){
    int N,D,X;
    scanf("%d%d%d",&N,&D,&X);
    int A[N];
    int count = 0;
    for(int i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }
    for(int i = 0; i < N; i++){
        int j = 0;
        for(int d = 1; d < D+1;d++){
            if(j*A[i]+1 == d){
                count++;
                j++;
            } 
        }
    }
    printf("%d\n",count+X);
    return 0;
}
