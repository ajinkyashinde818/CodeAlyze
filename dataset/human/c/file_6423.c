// Maximum Profit
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

const int MAX_N = 200000;

int main(void)
{
    int profit = 0, first_num = 0;
    int max_profit = 0;
    int input_num, ary_price[MAX_N];

    for(int i = 0; i < MAX_N; i++)
    {
        ary_price[i] = 0;
    }

    scanf("%d", &input_num);

    for(int i = 0; i < input_num; i++)
    {
        scanf("%d", &ary_price[i]);
    }

    max_profit = ary_price[input_num - 1] - ary_price[input_num - 2];

    for (int i = input_num - 1; i > 0; i--)
    {

        if( first_num < ary_price[i] )
        {
            // 利益の最大値の演算なので、引かれる数が大きい時のみ演算する
            first_num = ary_price[i];
        }
        else
        {
            // 引かれる数が小さくなった時は、以降の演算は実施しない
            continue;
        }

        for(int j = i - 1; j >= 0; j--)
        {
            profit = first_num - ary_price[j];

            if( max_profit < profit )
            {
                max_profit = profit;
            }
        }
    }

    printf("%d\n", max_profit);

    return 0;
}
