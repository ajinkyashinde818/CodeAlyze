#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    long long x;
    scanf("%lld", &x);

    switch( x%11 ){
    case 0:
        printf("%lld\n", (x/11)*2);
        break;
    case 1: case 2: case 3: case 4: case 5: case 6:
        printf("%lld\n", (x/11)*2+1);
        break;
    case 7: case 8: case 9: case 10:
        printf("%lld\n", (x/11)*2+2);
        break;
    }
    return 0;
}
