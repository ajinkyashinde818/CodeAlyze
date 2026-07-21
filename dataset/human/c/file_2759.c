#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint_fast32_t k, s, t = 0, i = 0, j = 0;
    scanf("%" SCNuFAST32 " %" SCNuFAST32, &k, &s);
    for (;;) {
        if (i > s || i > k) {
            break;
        } else if (j - i > k || j > s) {
            j = ++i;
        } else if (s - j > k) {
            ++j;
        } else {
            ++t, ++j;
        }
    }
    printf("%" PRIuFAST32 "\n", t);
    return 0;
}
