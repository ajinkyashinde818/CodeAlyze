#include <stdio.h>

int main(void){
    int h,w;
    int flag = 0;

    scanf("%d %d",&h,&w);
    char S[h+2][w+2];
    char s[h][w];
    for(int i = 0; i < h+2; i++){
        for(int j = 0; j < w+2; j++){
            S[i][j] = '.';
        }
    }


    for(int i = 0; i < h; i++){
        scanf("%s",s[i]);
        for(int j = 0; j < w; j++){
            S[i+1][j+1] = s[i][j];
        }
    }
    for(int i = 1; i < h+1; i++){
        for(int j = 1; j < w+1; j++){
                if((S[i][j]=='#') && (S[i-1][j]=='.') && (S[i][j-1]=='.') && (S[i+1][j]=='.') && (S[i][j+1]=='.')) flag = 1;
        }
    }

    if(flag == 1){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}
