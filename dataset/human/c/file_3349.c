#include <stdio.h>
#include <string.h>

#define S_MAX 1000000

int main(void) {
    char S[S_MAX];
    scanf("%s", S);

    int snum=strlen(S);

    char RS[snum];
    for (int i = snum; i >= 0; i--) {
        // printf("%d, %d, %c\n", i, snum-i, S[i-1]);
        RS[snum-i] = S[i-1];
    }

    for (int i = 0; i < snum;) {
        if (strncmp(&RS[i], "maerd", 5) == 0) {
            i = i + 5;
        } else if (strncmp(&RS[i], "remaerd", 7) == 0) {
            i = i + 7;
        } else if (strncmp(&RS[i], "esare", 5) == 0) {
            i = i + 5;
        } else if (strncmp(&RS[i], "resare", 6) == 0) {
            i = i + 6;
        } else {
            printf("NO\n");
            return 0;
        }
    }

    printf("%s\n", "YES");
    return 0;
}
