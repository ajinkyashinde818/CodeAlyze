#include <stdio.h>
#include <string.h>

int main(){
    char s[100001], tmp[8];
    char div[4][8] = {"dream", "dreamer", "erase", "eraser"};
    int ans = 1;
    scanf("%s", s);

    char *adr = s + strlen(s);
    for(int i = strlen(s) - 1; i >= 0;){
        int flag = 0;
        for(int j = 0; j < 4; j++){
            if(strncmp(adr - strlen(div[j]), div[j], strlen(div[j])) == 0){
                flag = 1;
                i -= strlen(div[j]);
                adr -= strlen(div[j]);
            }
        }
        if(!flag){
            ans = 0;
            break;
        }
    }
    printf((ans == 1) ? "YES\n" : "NO\n");
    return 0;
}
