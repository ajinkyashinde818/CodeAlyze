#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <math.h>
//#include <algorithm>
//#include <vector> 


int main(int argc, char* argv[])
{
    long a, b, c;
    scanf("%ld %ld %ld", &a, &b, &c);

    if(a+b>=c-1) {
        printf("%d\n", b+c);
    }
    else {
        printf("%d\n", a + b + 1 + b);
    }

    return 0;
}
