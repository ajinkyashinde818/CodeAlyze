#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);

    int num = 0;
    int res;
    for (int i=100; ; i--){
        if (a%i == 0 && b%i == 0){
            num++;
        }
        if (num == k){
            res = i;
            break;
        }
    }


    printf("%d\n", res);


    

    return 0;
}
