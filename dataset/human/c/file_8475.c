#include <stdio.h>

int main(void)
{
    int N, M, k;
    int A[101];
    int student;
    int i;
    int t;
    
    scanf("%d%d", &N, &M);
    
    for (i = 1; i <= N; i++){
        scanf("%d", &A[i]);
    }
    
    for (k = 1; k <= M; k++){
        student = 1;
        while (student != N){
            if (A[student] % k > A[student + 1] % k){
                t = A[student];
                A[student] = A[student + 1];
                A[student + 1] = t;
            }
            student++;
        }
    }
    
    for (i = 1; i <= N; i++){
        printf("%d\n", A[i]);
    }
    
    return (0);
}
