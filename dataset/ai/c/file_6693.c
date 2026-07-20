#include <stdio.h>
typedef union { int code; char letter; } Token;
int main(void)
{
    Token token; token.code = 35;
    printf("%d\n", token.code);
    return 0;
}
