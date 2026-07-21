#include <stdio.h>

int read(void)
{
    int ret;
    scanf("%d", &ret);
    return ret;
}

int main(void)
{
    int i, idx = 0;
    int data[10000];

    while((data[idx++] = read()) != 0);

    for(i=0;i<idx-1;i++) {
        printf("Case %d: %d\n", i+1, data[i]);
    }
    return 0;
}
