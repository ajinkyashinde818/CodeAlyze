#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /* code */
    int N, M;
    scanf("%d %d", &N, &M);
    if(N == M)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}
