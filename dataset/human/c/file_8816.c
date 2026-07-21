#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    int H, W;

    scanf("%d%d", &H, &W);

    char s[H][W+1];

    for(int i = 0; i < H; i++){
        scanf("%s", s[i]);
    }

    char t[H+2][W+3];

    for(int i = 0; i < W + 2; i++){
        t[0][i] = '.';
        t[H+1][i] = '.';
    }

    for(int i = 1; i <= H; i++){
        t[i][0] = '.';
        for(int j = 1; j <= W; j++){
            t[i][j] = s[i-1][j-1];
        }
        t[i][W+1] = '.';
    }

    int f = 0;

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(t[i][j] == '#' && t[i-1][j] == '.' && t[i][j-1] == '.' && t[i][j+1] == '.' && t[i+1][j] == '.'){
                f = 1;
                break;
            }
        }
    }

    if(f == 1){
        printf("No\n");
    }else{
        printf("Yes\n");
    }

    return 0;
}
