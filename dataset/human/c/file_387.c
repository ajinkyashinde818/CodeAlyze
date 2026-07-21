#include <stdio.h>

int main(void)
{
    
    char char_inputJoinData;
    int int_inputDisplayRatingData;

    scanf("%d %d", &char_inputJoinData, &int_inputDisplayRatingData);

    if (char_inputJoinData >= 10)
    {
        printf("%d", int_inputDisplayRatingData);
    }
    else
    {
        int int_innerRatingData;
        int_innerRatingData = int_inputDisplayRatingData + (10 - char_inputJoinData) * 100;
        printf("%d", int_innerRatingData);
    }

}
