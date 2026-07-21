#include <stdio.h>

int main() {
    int iCount, iIndex = 0;
    int iInputNum[10000];

    while (1)
    {
        scanf("%d", &iInputNum[iIndex]);

        if (iInputNum[iIndex] == 0) {
            break;
        }
        iIndex++;
    }

    for (iCount = 0; iCount < iIndex; iCount++) {
        printf("Case %d: %d\n", iCount + 1, iInputNum[iCount]);
    }
    
    return 0;
}
