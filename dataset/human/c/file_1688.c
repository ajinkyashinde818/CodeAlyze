#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int inputN, *inputA, *inputB, *inputC, answer = 0, tmpA;
    scanf("%d", &inputN);
    inputA = (int *)malloc(sizeof(int) * inputN);
    inputB = (int *)malloc(sizeof(int) * inputN);
    inputC = (int *)malloc(sizeof(int) * (inputN - 1));
    for (int count = 0; count < inputN; count++)
    {
        scanf("%d", &inputA[count]);
    }
    for (int count = 0; count < inputN; count++)
    {
        scanf("%d", &inputB[count]);
    }
    for (int count = 0; count < inputN - 1; count++)
    {
        scanf("%d", &inputC[count]);
    }
    for (int count = 0; count < inputN; count++)
    {
        if (count > 0)
        {
            tmpA = inputA[count - 1];
        }
        else
        {
            tmpA = -1;
        }
        answer += inputB[count];
        if (tmpA + 1 == inputA[count])
        {
            answer += inputC[tmpA - 1];
        }
    }
    printf("%d", answer);

    free(inputA);
    free(inputB);
    free(inputC);

    return 0;
}
