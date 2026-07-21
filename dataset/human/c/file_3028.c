#include <stdio.h>

int main()
{
    int K, N;
    int A[200000];
    scanf("%d %d", &K, &N);
    for (int i=0;i<N;i++) {
        scanf("%d", &A[i]);
    }
    //bubble sort
    int tmp, flag = 1;
    while (flag) {
        flag = 0;
        for (int j=N-1;j>0;j--) {
            if (A[j] < A[j-1]) {
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
            }
        }
    }
    
    int len_dif;
    for (int i=0;i<N;i++) {
        if (i==0) {
            len_dif = A[i] + K - A[N-1];
        } else {
            if (A[i] - A[i-1] > len_dif) {
                len_dif = A[i] - A[i-1];
            }
        }
    }

    printf("%d\n", K-len_dif);

    return 0;
}
