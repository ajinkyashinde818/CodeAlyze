#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int N;
    char buf[32];
    scanf("%d", &N);

    sprintf(buf, "%d", N);
    if ( strchr(buf, '9') == NULL ){
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}
