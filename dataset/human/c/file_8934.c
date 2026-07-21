#include<stdio.h>
#include<stdlib.h>

int main(){
    int h, w, i, j, flag;
    flag = 0;
    scanf("%d %d", &h, &w);
    char buf[h][w];

    for(i = 0; i < h ;i++){
        scanf("%s", buf[i]);
    }

    // for(i = 0; i < h ;i++){
    //     for(j = 0; j < w; j++){
    //         printf("%c", buf[i][j]);
    //     }
    //     printf("\n");
    // }

    for(i = 0; i < h && !flag;i++){
        for(j = 0; j < w && !flag; j++){
            if(buf[i][j] == '.') continue;
            if(j > 0 && buf[i][j - 1] == '#') continue;
            if(j < w - 1 && buf[i][j + 1] == '#') continue;
            if(i > 0 && buf[i - 1][j] == '#') continue;
            if(i < h - 1 && buf[i + 1][j] == '#') continue;
            flag = 1;
        }
        if(flag) break;
    }

    printf("%s\n", flag ? "No" : "Yes");
    return 0;
}
