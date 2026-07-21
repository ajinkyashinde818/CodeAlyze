#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    char S[100001];

    scanf("%s", S);

    int len = strlen(S);

    int t = 0;

    while(true){
        if(S[t] == 'd' && S[t+1] == 'r' && S[t+2] == 'e' && S[t+3] == 'a' && S[t+4] == 'm' && S[t+5] == 'e' && S[t+6] == 'r' && S[t+7] != 'a'){
            t += 7;
        }else if(S[t] == 'd' && S[t+1] == 'r' && S[t+2] == 'e' && S[t+3] == 'a' && S[t+4] == 'm'){
            t += 5;
        }else if(S[t] == 'e' && S[t+1] == 'r' && S[t+2] == 'a' && S[t+3] == 's' && S[t+4] == 'e' && S[t+5] == 'r' && S[t+6] != 'a'){
            t += 6;
        }else if(S[t] == 'e' && S[t+1] == 'r' && S[t+2] == 'a' && S[t+3] == 's' && S[t+4] == 'e'){
            t += 5;
        }else{
            break;
        }
    }

    if(t == len){
        printf("YES\n");
    }else{
        printf("NO\n");
    }

    return 0;
}
