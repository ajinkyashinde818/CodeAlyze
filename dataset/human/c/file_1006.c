#include <stdio.h>

int main(void)
{
    int n, k[100];
    char s[101];
    int i;
    char table[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int c;
    
    while (1){
        scanf("%d", &n);
        if (n == 0){
            break;
        }
        for (i = 0; i < n; i++){
            scanf("%d", &k[i]);
        }
        scanf("%s", s);
        
        i = 0;
        while (s[i] != '\0'){
            c = s[i];
            if ('a' <= c && c <= 'z'){
                c = c - 'a';
            }
            else {
                c = c - 'A' + 26;
            }
            
            c = c - k[i % n] + 52;
            c %= 52;
            
            s[i] = table[c];
            i++;
        }
        
        printf("%s\n", s);
    }
    
    return (0);
}
