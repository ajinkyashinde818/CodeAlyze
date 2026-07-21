#include <stdio.h>
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a>b)?(a):(b))
 
int main() {
    int n, k, sk, i;
    char s[20];
    scanf("%d %s %d", &n, s, &k);

    sk = s[k-1];
    for (i = 0; s[i]; i++) {
        if (s[i] != sk) {
            s[i] = '*';
        }
    }

    printf("%s", s);
    
    return 0;
}
