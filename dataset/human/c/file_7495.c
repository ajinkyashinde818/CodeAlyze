#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int in, i;
    char line[256];

    for (i=1; ; i++) {

        memset(line, 0, sizeof(line));
        if (!fgets(line, sizeof(line), stdin)) {
            fprintf(stderr, "error input val\n");
            return -1;
        }

        if (sscanf(line, "%d", &in) != 1) {
            fprintf(stderr, "error input format\n");
            return -1;
        }

        if (!in) {
            break;
        }
        printf("Case %d: %d\n", i, in);
    }

    return 0;
}
