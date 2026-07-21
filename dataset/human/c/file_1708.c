#include <stdio.h>

int main(){
    int N,i,old_index,result;
    int A[100],B[100],C[100];

    old_index = -1;
    result = 0;
    scanf("%d",&N);

    for(i = 1 ; i < N+1 ; i++){
        scanf("%d",&A[i]);
    }
    for(i = 1 ; i < N+1 ; i++){
        scanf("%d",&B[i]);
    }
    for(i = 1 ; i < N ; i++){
        scanf("%d",&C[i]);
    }

    for(i = 1 ; i < N + 1 ; i++){
        result += B[A[i]];
        //printf("%d点もらいました\n",B[A[i]]);
        if((A[i] - old_index) == 1){
            result += C[old_index];
            //printf("追加で%dもらいました\n",C[old_index]);
        }
        old_index = A[i];
    }
    printf("%d",result);

    return 0;

}
