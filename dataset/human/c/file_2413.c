#include <stdio.h>

int main(void)
{
    char s[4];
    int i, a, b, c;

    scanf("%s", s);

    a = b = c = 0;
    for (i=0; i<3; i++) {
        if (s[i]=='a')      a++;
        else if (s[i]=='b') b++;
        else if (s[i]=='c') c++;
    }

    if (a==1 && b==1 && c==1)   printf("Yes\n");
    else                        printf("No\n");

    return 0;
}
