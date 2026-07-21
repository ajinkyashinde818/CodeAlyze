#include <string.h>
#include <stdio.h>

int main(void)
{
    char a[10],b[10];
    scanf("%s%s",a,b);
    if (a[0] > b[0]) {
        printf(">\n");
    }else if (a[0] < b[0]) {
        printf("<\n");
    }else{
        printf("=\n");
    }
    return 0;
}
