#include <stdio.h>
#include <stdlib.h>

void solve(int N, int num, char *str) {
    char ch = str[num - 1];
    int i;
    for(i = 0; str[i] != '\0'; ++i) {
        if(str[i] != ch) { str[i] = '*'; }
    }
    printf("%s\n", str);
}

int main()
{
    int n, k;
    scanf("%d", &n);
    char *str = (char*)malloc((n+5)*sizeof(char));
    scanf("%s", str);
    scanf("%d", &k);
    //printf("%s", str);
    solve(n, k, str);
    return 0;
}
