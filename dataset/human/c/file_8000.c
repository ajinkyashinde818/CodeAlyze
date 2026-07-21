#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define BUF_SIZE 20

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

#define DIVISOR 1000000007
#define WIDTH_MAX 1000000
#define HEIGHT_MAX WIDTH_MAX
// WIDTH_MAX*2/3 < 666667
#define COMBI_MAX 670000

struct pair {
    int x;
    int y;
};

// assume that a < b
struct pair gcdext(int a, int b) {
    // 0*x + 1*y = 1
    if(a==0) { return (struct pair){0, 1}; }
    struct pair p = gcdext(b%a, a);
    return (struct pair){p.y - (b/a)*p.x, p.x};
}

int main(void) {
    int width, height;
    int i;
    get_int2(&width, &height);

    // assume that p1: # of (+1, +2)
    //             p2: # of (+2, +1)
    // x = 2*p1 + p2
    // y = p1 + 2*p2
    // => x+y = 3(p1+p2) <= requires that x+y should be divided by 3
    if((width+height)%3) goto impossible;
    int p1_p2 = (width+height)/3;
    int p1 = width - p1_p2;
    int p2 = p1_p2 - p1;
    if(p1 < 0 || p2 < 0) goto impossible;

    // calc x! and inv(x!) in advance..
    static uint64_t factorial[COMBI_MAX];
    static uint64_t inv_factorial[COMBI_MAX];
    factorial[0] = factorial[1] = 1;
    inv_factorial[0] = inv_factorial[1] = 1;
    for(i = 2; i <= p1_p2; i++) {
        factorial[i] = (factorial[i-1]*i)%DIVISOR;

        struct pair p = gcdext(i, DIVISOR);
        // positive number
        uint64_t inv = (p.x + DIVISOR)%DIVISOR;
        inv_factorial[i] = (inv_factorial[i-1]*inv)%DIVISOR;
    }

    // calc (p1_p2)_C_p1
    uint64_t ans = 1;
    ans = (ans * factorial[p1_p2])%DIVISOR;
    ans = (ans * inv_factorial[p1])%DIVISOR;
    ans = (ans * inv_factorial[p2])%DIVISOR;
    // ans must be less than DIVISOR < MAX_INT
    printf("%d\n", (int)ans);
    return 0;
impossible:
    printf("0\n");
    return 0;
}
