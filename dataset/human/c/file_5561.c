#include <stdio.h>
#include <math.h>

int primenumber(int n);

int main(void)
{
    int n;

    while (1){
        scanf("%d", &n);
        if (n == 0){
            break;
        }

        printf("%d\n", primenumber(n));
    }
    return (0);
}
int primenumber(int n)
{
    int i,j;
    int x;
    int flag;
    int sum;

    i = 0;
    x = 2;
    sum = 0;
    while (i < n){
        flag = 0;
        if (x % 2 == 0 && x != 2){
                flag = 1;
            }
        for (j = 3; j <= sqrt(x); j++){
            if (x % j == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            i++;
            sum += x;
            //printf("<%d %d %d>\n", i, sum, x);
        }
        x++;
    }
    return (sum);
}
