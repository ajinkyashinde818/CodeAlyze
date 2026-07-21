#include <stdio.h>

int main()
{
    int n;
    int index;
    scanf("%d", &n);

    int A[n];
    int B[n];
    int C[n - 1];
    int count = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        /* printf("A_%d = %d\n", i, A[i]); */
        }
    for(int i  = 0; i < n; i++){
        scanf("%d", &B[i]);
        /* printf("B_%d = %d\n", i, B[i]); */
        }

    for(int i = 0; i < n - 1; i++){
        scanf("%d", &C[i]);
        /* printf("C_%d = %d\n", i, C[i]); */
        }
    for(int j=0 ; j < n ; j++){
        count += B[j];
        /* printf("add B_%d = %d\n", j, B[j]); */
        if(A[j] == A[j+1] - 1){
            index=A[j];
            count += C[index - 1];
            /* printf("add C_%d = %d\n", index - 1, C[index -1]); */
        }
        /* printf("coun = %d\n", count); */
    }
    printf("%d", count);
}
