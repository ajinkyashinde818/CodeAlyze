#include <stdio.h>

int main(void)
{
    char s[11];
    int n, k;

    char t;
    int i;

    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &k);

    t = s[k-1];

    for(i=0;i<n;i++){
        if(s[i] == t){
            printf("%c", t);
        }else{
            printf("*");
        }
    }

    return 0;
}
