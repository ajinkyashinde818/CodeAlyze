#include <stdio.h>

int main(void)
{
    int a,b,x,y,z,count = 0;
    scanf("%d%d",&a,&b);
    for (x = 0; x <= a; x++) {
        for (y = 0; y <= a; y++) {
            z = b - x - y;
            if (z <= a && z >= 0) {
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
