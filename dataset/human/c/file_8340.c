#include <stdio.h>
int main(void){
    int n, k;
    char s[16];
    scanf("%d %s %d", &n, s, &k);
    char ch = s[k-1];
    for(int i = 0; i < n; i++) {
        if(s[i] == ch) printf("%c", s[i]);
        else printf("*");
    }
}
