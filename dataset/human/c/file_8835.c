#include <stdio.h>
int main(void){
    int h, w;
    char s[50+5][50+5];
    scanf("%d %d", &h, &w);
    
    for(int i=1; i<=h; i++){
        scanf("%s", &s[i][1]);
    }
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(s[i][j]=='#'){
                // 独立した黒なら不可能
                if(s[i+1][j]=='.' && s[i-1][j]=='.' && s[i][j+1]=='.' && s[i][j-1]=='.'){
                    printf("No\n");
                    return 0;
                }
            }
        }
    }
    printf("Yes\n");
    return 0;
}
