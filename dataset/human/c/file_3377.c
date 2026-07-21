#include <stdio.h>
#include <string.h>


int main(void)
{
    int ok = 0;
    char S[1000001];
    char temp[1024];
    char *p;

    scanf("%s", S);
    p = S;
    while(*p != '\0'){
        if(strlen(p) >= 5){
            strncpy(temp, p, 5);
            temp[5] = '\0';
        }else{
            break;
        }

        if(strcmp(temp, "dream") != 0 && strcmp(temp, "erase") != 0){
            break;
        }

        p += 5;

        if(p[0] == 'e' && p[1] == 'r' && p[2] != 'a'){
            p += 2;
        }else if(p[0] == 'r'){
            p += 1;
        }
    }

    if(*p == '\0'){
        printf("YES\n");
    }else{
        printf("NO\n");
    }

    return 0;
}
