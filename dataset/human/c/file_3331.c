#include <stdio.h>
#include <string.h>
 
char s[100001];
char * word[] = {"dream", "dreamer", "erase", "eraser"};
char dp[100001];
int main(){
    memset(dp,0,sizeof(dp));
    scanf("%s", s);
 
    int len = strlen(s);
    int index = 0;
    
    dp[0] = 1;
    for(int index = 0; index < len; index++){
        if(dp[index] == 0){
            continue;
        }
        for(int i = 0; i < 4; i++){
            if(strncmp(word[i],s+index,strlen(word[i])) == 0){
                dp[index+strlen(word[i])] = 1;
            }
        }
    }
    puts(dp[len]?"YES":"NO");
}
