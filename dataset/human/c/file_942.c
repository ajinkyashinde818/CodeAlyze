#include <stdio.h>

int main()
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    if (a == 0) {
        if (1868 <= b && b <= 1911) {
            printf("M");
            printf("%d\n", b - 1867);
        } else if (1912 <= b && b <= 1925) {
            printf("T");
            printf("%d\n", b - 1911);
        } else if (1926 <= b && b <= 1988) {
            printf("S");
            printf("%d\n", b - 1925);
        } else if (1989 <= b) {
            printf("H");
            printf("%d\n", b - 1988);
        }
    } else if (a == 1) {
        printf("%d\n", b + 1867);
    } else if (a == 2) {
        printf("%d\n", b + 1911);
    } else if (a == 3) {
        printf("%d\n", b + 1925);
    } else if (a == 4) {
        printf("%d\n", b + 1988);
    }
    
    return 0;
}
