#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint_fast32_t a, b, c, d;
    scanf("%" SCNuFAST32 " %" SCNuFAST32 " %" SCNuFAST32 " %" SCNuFAST32,
          &a, &b, &c, &d);
    printf("%" PRIuFAST32 "\n", (a * b > c * d) ? (a * b) : (c * d));
    return 0;
}
