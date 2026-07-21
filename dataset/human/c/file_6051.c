#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main()
{
    int32_t n                     ,
            value                 ,
            min                   ,
            diff_max = -1000000000;

    scanf("%"PRId32, &n    );
    scanf("%"PRId32, &value);
    min = value;

    for(int32_t i=1; i<n; ++i){
        scanf("%"PRId32, &value);
        if( diff_max < (value - min))
            diff_max =  value - min;
        if( min > value)
            min = value;
    }
    printf("%"PRId32"\n", diff_max);

    return 0;
}
