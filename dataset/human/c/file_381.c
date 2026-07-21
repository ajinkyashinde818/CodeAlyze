#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, r, dr;

    scanf("%d %d", &n, &r);

    if( n < 10)
    {
        dr = r + 100*(10-n);    
    }
    else
    {
        dr = r;
    }

    printf("%d", dr);

	return 0;
}
