#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {

    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    printf("%d",(a*b>=c*d ? a*b : c*d));


    return 0;

}
