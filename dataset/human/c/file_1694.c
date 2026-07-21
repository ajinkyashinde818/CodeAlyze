#include <stdio.h>

int
main(int argc, char *argv[])
{
    int N;
    int A[20], B[20], C[20];
    int i;
    int safficient=0;

    scanf("%d", &N);
    for (i=0; i<N; i++)
        scanf("%d", A+i);
    for (i=0; i<N; i++)
        scanf("%d", B+i);
    for (i=0; i<N-1; i++)
        scanf("%d", C+i);

    for (i=0; i<N; i++) {
        safficient = safficient + B[A[i]-1];
        if (i>0 && A[i]-A[i-1]==1)
            safficient = safficient + C[A[i-1]-1];
    }
    printf("%d\n", safficient);

    return 0;
}
