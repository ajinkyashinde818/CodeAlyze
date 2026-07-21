#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
        char s[1000000];
        scanf("%s", s);
        for (int i = 0; i < strlen(s); i++) {
                if (s[i]=='9') {
                        printf("Yes\n");
                        return 0;
                }
        }
        printf("No\n");
        return 0;
}
