//１つの整数 x を読み込み、それをそのまま出力するプログラム
#include <stdio.h>

int main(void)
{
    //変数定義
    int iCount;
    int iInputDataSet;

    //変数の初期化
    iInputDataSet = 1;
    iCount = 1;

    while (iInputDataSet != 0)
    {
        scanf("%d",&iInputDataSet);
        if (iInputDataSet != 0)
        {
            printf("Case %d: %d\n",iCount,iInputDataSet);
        }
        iCount++;
    }
    return 0;
}
