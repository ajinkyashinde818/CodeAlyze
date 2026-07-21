#include <stdio.h>

int main(void)
{

    int i_containNum = 0;
    double i_inputNumA, i_inputNumB, i_minNum, i_maxNum, i_divideNum, displayNum;
    char c_flag = 0;
    scanf("%lf%lf", &i_inputNumA, &i_inputNumB);

    int ia_primeList[100000] = {0};
    if (i_inputNumA > i_inputNumB)
    {
        i_minNum = i_inputNumB;
        i_maxNum = i_inputNumA;
    }
    else
    {
        i_minNum = i_inputNumA;
        i_maxNum = i_inputNumB;
    }
    for (int count = 1; count <= i_minNum; count++)
    {
        if ((int) i_inputNumA % count == 0 && (int) i_inputNumB % count == 0)
        {
            ia_primeList[i_containNum] = count;
            i_containNum++;
        }
    }

    for (int index = 0; ia_primeList[index] != 0; index++)
    {
        if ((int) i_inputNumA % ia_primeList[index] == 0 && (int) i_inputNumB % ia_primeList[index] == 0)
        {
            i_divideNum = ia_primeList[index];
        }
    }

    displayNum = i_minNum * (i_maxNum / i_divideNum);

    printf("%.0lf", displayNum);
}
