#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE         (1024)

char buf[BUFSIZE];

long
readnum()
{
    long        ret;
    char        *bp;

    bp = fgets(buf, BUFSIZE, stdin);
    if (bp == NULL) goto err;
    ret = atol(buf);
    return ret;

  err:
    perror("error fgets");
    exit(EXIT_FAILURE);
}

#define MAX(a, b)       ((a) < (b) ? (b) : (a))
#define MIN(a, b)       ((a) > (b) ? (b) : (a))

int
main()
{
    long        num;
    long        minnum;
    long        dif;
    long        maxdif;
    long        tn;
    int         idx;

    tn = readnum();

    minnum = readnum();
    --tn;
    maxdif = -1000 * 1000 * 1000;
    for (idx = 0; idx < tn; ++idx) {
        num = readnum();
        dif = num - minnum;
        maxdif = MAX(maxdif, dif);
        minnum = MIN(minnum, num);

//        printf("num = %ld, dif = %ld, max = %ld, min = %ld\n", num, dif, maxdif, minnum);
    }
    printf("%ld\n", maxdif);
}
