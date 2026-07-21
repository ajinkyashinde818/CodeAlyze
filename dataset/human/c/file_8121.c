#include <stdio.h>

int main()
{
    unsigned int a, b, c, d;

    if ( scanf("%u %u %u %u", &a, &b, &c, &d) != 4) {
        printf("Error!\n");
        return -1;
    }

    unsigned int area_ab = a * b, area_cd = c * d;

    if (area_ab > area_cd) printf("%u", area_ab);
    else                   printf("%u", area_cd);

    return 0;
}
