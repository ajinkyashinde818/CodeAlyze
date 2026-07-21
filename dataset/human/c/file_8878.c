#include<stdio.h>

int main(void){
    char mass[55][55];
    int h, w;
    scanf("%d""%d", &h, &w);
    for(int i = 0; i < h; i++){
        scanf("%s", mass[i]);
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mass[i][j] == '#'){
                if(mass[i - 1][j] != '#' && mass[i + 1][j] != '#' && mass[i][j - 1] != '#' && mass[i][j + 1] != '#'){
                    printf("No\n");
                    return 0;
                }
            }
        }
    }
    printf("Yes\n");
    return 0;
}
