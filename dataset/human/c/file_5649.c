#include<stdio.h>

unsigned long x;
unsigned long i = 0;

int main()
{
    int tmp = 0;

    scanf("%ld", &x);

    i = (x / 11) * 2;
    x = x % 11;

    while(tmp < x){
        i++;
        (i % 2) ? (tmp += 6) : (tmp += 5);
    }

    printf("%lu\n", i);

    return 0;
}
