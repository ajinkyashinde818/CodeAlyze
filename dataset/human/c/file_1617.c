#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char s[1000000];
    scanf("%s", s);
    int len = strlen(s);
    int ans = 0;
    for(int i = 0, j = len - 1; i <= j; i++, j--){
        if(s[i] == s[j]){
            continue;
        }
        while(s[i] == 'x'){
            i++;
            ans++;
        }
        while(s[j] == 'x'){
            j--;
            ans++;
        }
        if(s[i] != s[j]){
            printf("-1");
            return 0;
        }
    }
    printf("%d", ans);
    return 0;
}
