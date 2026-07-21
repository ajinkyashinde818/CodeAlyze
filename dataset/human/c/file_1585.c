#include <stdio.h>
#include <string.h>
#define N (100010)
char s[N];
int main(){
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    for (int i = 0, j = n-1; i < j;){
        //printf("%d %d\n", i, j);
        if (s[i] != 'x' && s[j] != 'x'){
            if (s[i] != s[j]){
                printf("-1\n");
                return 0;
            }
            else {
                i++;
                j--;
            }
        }
        else if (s[i] == 'x' && s[j] != 'x'){
            i++;
            ans++;
        }
        else if (s[j] == 'x' && s[i] != 'x'){
            j--;
            ans++;
        }
        else {
            i++;
            j--;
        }
    }
    printf("%d\n", ans);
}
