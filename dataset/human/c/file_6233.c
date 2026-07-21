#include <stdio.h>
 
#define TIME_MIN (2)
#define TIME_MAX (200000)
#define VALUE_MIN (1)
#define VALUE_MAX (1000000000)
#define FAILURE   (-1000000001)
#define SUCCESS   (0)
 
int get_int(int *p_num, int min, int max);
int judge_constraint(int test_num, int min, int max);
int max_profit(int size);
 
int main(void)
{
    int time_cnt;
    int rslt;
     
    if(get_int(&time_cnt, TIME_MIN, TIME_MAX) == FAILURE)
    {
        return FAILURE;
    }
 
    if((rslt = max_profit(time_cnt)) == FAILURE)
    {
        return FAILURE;
    }
    
    printf("%d\n", rslt);
     
    return SUCCESS;
}
 
int max_profit(int size)
{
    int min;
    int max;
    int current;
    int i;
     
    /* init  */
    if(get_int(&current, VALUE_MIN, VALUE_MAX) == FAILURE)
    {
        return FAILURE;
    }
    min = current;
    max = VALUE_MAX * -1;
     
    /* calc */
    for(i = 1; i < size; i++)
    {
        if(get_int(&current, VALUE_MIN, VALUE_MAX))
        {
            return FAILURE;
        }
        if(max < current - min)
        {
            max = current - min;
        }
        if(min > current)
        {
            min = current;
        }
    }
     
     
    return max;
}
 
int get_int(int *p_num, int min, int max)
{
    scanf("%d", p_num);
     
    if(judge_constraint(*p_num, min, max) == FAILURE)
    {
        return FAILURE;
    }
     
    return SUCCESS;
}
int judge_constraint(int test_num, int min, int max)
{
    if(test_num < min || test_num > max)
    {
        return FAILURE;
    }
     
    return SUCCESS;
}
