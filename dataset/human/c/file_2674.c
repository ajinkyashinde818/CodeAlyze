#include <stdio.h>
#include <string.h>

int dp[512][512][10][3][2];
char look[512];
int mod;
int len;

int min(int a, int b)
{
    return (b > a ? a : b);
}

int memo(int digits, int div, int now, int upd, int same)
{
    int i, j;
    int ans;
    
    if (digits == len){
        return (!div);
    }
    
    if (dp[digits][div][now][upd][same] >= 0){
        return (dp[digits][div][now][upd][same]);
    }
    
    ans = 0;
    if (upd == 2){
        if (digits != len - 1){      // if all digits of number equals to zero, that isn't a zig-zag number
            ans += memo(digits + 1, div * 10 % mod, now, 2, same && (look[digits] - '0') == 0);
            ans %= 10000;
        }
        for (i = now + 1; i <= (same ? look[digits] - '0' : 9); i++){
            ans += memo(digits + 1, (div * 10 + i) % mod, i, 1, same && (look[digits] - '0') == i);
            if (digits != len - 1){ // 1-digit number will be same at two status, up and down
                ans += memo(digits + 1, (div * 10 + i) % mod, i, 0, same && (look[digits] - '0') == i);
            }
            ans %= 10000;
        }
    }
    else if (upd == 0){ //increase
        for (i = now + 1; i <= (same ? look[digits] - '0' : 9); i++){
            ans += memo(digits + 1, (div * 10 + i) % mod, i, upd ^ 1, same && (look[digits] - '0') == i);
            ans %= 10000;
        }
    }
    else {              //decrease
        for (i = min(now - 1, same ? look[digits] - '0' : now - 1); i >= 0; i--){
            ans += memo(digits + 1, (div * 10 + i) % mod, i, upd ^ 1, same && (look[digits] - '0') == i);
            ans %= 10000;
        }
    }
    
    return (dp[digits][div][now][upd][same] = ans % 10000);
}

int ZigZag(char *str)
{
    int len = strlen(str);
    int up;
    int i;
    
    if (len == 1){
        return (1);
    }
    if (len == 2){
        return (str[0] != str[1]);
    }
    up = str[0] < str[1];
    for (i = 1; i < len; i++){
        if (up && str[i] > str[i - 1]){
            up ^= 1;
        }
        else if (!up && str[i] < str[i - 1]){
            up ^= 1;
        }
        else {
            return (0);
        }
    }
    return (1);
}

int main(void)
{
    int first, next;
    char start[512], end[512];
    
    scanf("%s", start);
    scanf("%s", end);
    scanf("%d", &mod);
    
    memset(dp, -1, sizeof(dp));
    
    sprintf(look, "0%s", start);
    len = strlen(look);
    first = memo(0, 0, 0, 2, 1);
    
    memset(dp, -1, sizeof(dp));
    
    sprintf(look, "0%s", end);
    len = strlen(look);
    next = memo(0, 0, 0, 2, 1);
    
    printf("%d\n", (next - first + ZigZag(start) + 10000) % 10000);
    
    return (0);
}
