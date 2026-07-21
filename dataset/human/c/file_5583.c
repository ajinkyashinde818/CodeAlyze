#include <stdio.h>
#define LENGTH 256

int main()
{
    char input[LENGTH];
    int N, i;
    int result;
    fgets(input, LENGTH-1, stdin);
    sscanf(input, "%d %d", &N, &i);
    result = N - i + 1;
    printf("%d\n", result);
    return 0;
}
