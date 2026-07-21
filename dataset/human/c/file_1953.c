#include<stdio.h> //B[A[i]]
int main(){
    int N,tmp;
    int A[21];
    int B[21];
    int C[21];
    int ac[21];
    int value = 0;
    
    scanf("%d",&N);
    for(int i = 1 ; i <= N ; i++){
        scanf("%d",&A[i]);
    }
    for(int i = 1 ; i <= N ; i++){
        scanf("%d",&B[i]);
    }
    for(int i = 1 ; i <= N-1 ; i++){
        scanf("%d",&C[i]);
    }
    tmp = A[0];
    for(int i = 1 ; i <= N ; i++){ //実際に食べた順番
        value += B[A[i]];
//        printf("value is %d\n",value);
        if(i > 1 && A[i]-tmp == 1){
            value += C[tmp];
//            printf("value plus ! c[%d] = %d\n",i,C[tmp]);
        }
        tmp = A[i];
    }
    printf("%d\n",value);
    
    return 0;
}
