#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int A[N],B[N],C[N-1];
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&B[i]);
    }
    for (int i = 0; i < N-1; i++)
    {
        scanf("%d",&C[i]);
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int id = A[i];
        sum += B[id-1];
        if (i > 0)
        {
            if (A[i] - A[i-1] == 1)
            {
                sum += C[A[i-1]-1];
            }            
        }        
    }

    printf("%d\n",sum);
    return 0;
}
