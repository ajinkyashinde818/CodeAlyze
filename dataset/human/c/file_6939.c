#include <stdio.h>

int main(void)
{
    int H;
    int W;
    scanf("%d %d", &H, &W);
    while (H != 0 || W != 0) {
        for (int i = 1; i < H + 1; ++i) {
            if (i % 2 == 1) {
                if (W % 2 == 1) {
                    for (int j = 0; j < (W - 1) / 2; ++j) {
                        printf("#.");
                    }
                    printf("#\n");
                } else {
                    for (int j = 0; j < (W - 2) / 2; ++j) {
                        printf("#.");
                }
                    printf("#.\n");
                }
            } else {
                if (W % 2 == 1) {
                    for (int j = 0; j < ( W - 1 ) / 2; ++j) {
                        printf(".#");
                    }
                    printf(".\n");
                } else {
                    for (int j = 0; j < ( W - 2 ) / 2; ++j) {
                        printf(".#");
                    }
                    printf(".#\n");
                }
            }
        }
        printf("\n");
        scanf("%d %d", &H, &W);
    }
    return 0;
}
