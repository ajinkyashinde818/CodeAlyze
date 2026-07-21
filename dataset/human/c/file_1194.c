#include <stdio.h>
#include <string.h>

int main(void)
{
    int smin=123, smax=0, tmax=0, i, slen, tlen;
    char s[200], t[200];

    scanf("%s", s);
    scanf("%s", t);

    slen = strlen(s);
    tlen = strlen(t);

    for (i = 0; i < slen; i++){
        if(s[i] < smin){
            smin = s[i];
        }
        if(s[i] > smax){
            smax = s[i];
        }
    }
    for (i = 0; i < tlen; i++){
        if(t[i] > tmax){
            tmax = t[i];
        }
    }

    if(smin < tmax){
        printf("Yes\n");
    } else if(tmax < smin){
        printf("No\n");
    } else {
        if(smax > tmax){
            printf("No\n");
        } else if(smax < tmax){
            printf("Yes\n");
        } else {
            if(slen < tlen){
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}
