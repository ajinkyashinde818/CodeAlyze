#include "stdio.h"
#include "string.h"
 
int main()
{
    int i, j;
    char a, s[3];
    scanf("%s", s);
    for (i = 0; s[i] != 0; i++) {
         for (j = i + 1; s[j] != 0; j++) {
              if (s[i] > s[j]) {
                                    a = s[i];
                                    s[i] = s[j];
                                    s[j] = a;
              }
         }
    }
 
    if (strcmp(s, "abc") == 0)
        printf("Yes\n");
    else
        printf("No\n");
 
    return 0;
 
}
