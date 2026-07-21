#include <stdio.h>
#include <string.h>
 
int main(){
 
    char divide[4][8] = {"dream", "dreamer", "erase", "eraser"};
    int dp[100010];
    int len;
    int i, j;
 
    char S[100010];
    scanf("%s", S);
    len = strlen(S);
 
    dp[0] = 1;
    
    for(i = 1; i < len; i++){
        dp[i] = 0;
    }
    
    for(i = 0; i < len; ++i){
        for(j = 0; j < 4; j++){
            if(!strncmp(S+i, divide[j], strlen(divide[j]))){
                dp[i + strlen(divide[j])] = dp[i]; 
            }
        }
    }
    
    if(dp[len]) printf("YES");
    else printf("NO");
    return 0;
}
