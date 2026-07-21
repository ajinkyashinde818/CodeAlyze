#include <stdio.h>

int main() {
    int R, G, B, N;
    int Ri, Gi, Bi;
    int N_tmp, N_tmp_tmp;
    long A = 0;

    scanf("%d %d %d %d", &R, &G, &B, &N);

    Ri = N / R;
    for (; Ri >= 0; Ri--) {
        N_tmp = N;
        N_tmp -= Ri * R;
        if (N_tmp == 0) {
            A++;
            continue;
        }
        Gi = N_tmp / G;
        for (; Gi >= 0; Gi--) {
            N_tmp_tmp = N_tmp;
            N_tmp_tmp -= Gi * G;
            if (N_tmp_tmp == 0) {
                A++;
                continue;
            }
            Bi = N_tmp_tmp / B;
            N_tmp_tmp -= Bi * B;
            if (N_tmp_tmp == 0) {
                A++;
            }
        }
    }

    printf("%ld", A);

    return 0;
}
