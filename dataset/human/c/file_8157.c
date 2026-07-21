#include <stdio.h>

int main()
{
    int a, b, c, d, area1, area2;
    
    scanf( "%d %d %d %d", &a, &b, &c, &d );
    area1 = a * b;
    area2 = c * d;

    if( area1 > area2 ) 
        printf( "%d", area1 );
    else if (area1 < area2)
        printf("%d", area2);
    else
        printf("%d", area1);
    return 0;
}
