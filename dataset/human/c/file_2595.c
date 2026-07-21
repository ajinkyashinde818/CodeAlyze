#include<stdio.h>
int main() {
    char s[4];
    scanf("%s", &s);
    int i, a, b, c;
    a = b = c = 0;
    for (i = 0; i < 3; i++) {
        if (s[i] == 'a')
            a = 3;
        if (s[i] == 'b')
            b = 3;
        if (s[i] == 'c')
            c = 3;
    }
    if (a == 3 && b == 3 && c == 3)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
