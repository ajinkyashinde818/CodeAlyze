#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char s[3];
    scanf("%s", s);

    int isCheck = 0;
    if (s[0] == 'a') {
        if (s[1] == 'b' && s[2] == 'c') {
            isCheck = 1;
        }
        if (s[1] == 'c' && s[2] == 'b') {
            isCheck = 1;
        }

    }
    if (s[0] == 'b') {
        if (s[1] == 'a' && s[2] == 'c') {
            isCheck = 1;
        }
        if (s[1] == 'c' && s[2] == 'a') {
            isCheck = 1;
        }
    }
    if (s[0] == 'c') {
        if (s[1] == 'a' && s[2] == 'b') {
            isCheck = 1;
        }
        if (s[1] == 'b' && s[2] == 'a') {
            isCheck = 1;
        }
    }
    printf("%s", (isCheck == 1 ? "Yes" : "No"));




    return 0;

}
