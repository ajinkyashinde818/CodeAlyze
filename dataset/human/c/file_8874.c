#include <stdio.h>

int main()
{
    int H;
    int W;
    char canvas[50][50];
    int i;
    int j;
    int flag;

    scanf("%d %d%*c", &H, &W);

    for(i = 0; i < H; i++) {
        for(j = 0; j < W; j++) {
            scanf("%c", &canvas[i][j]);
        }
        scanf("%*c");
    }

    for(i = 0; i < H; i++) {
        for(j = 0; j < W; j++) {
            flag = 0;
            if(canvas[i][j] == '#') {
                if(i > 0 && canvas[i-1][j] == '#') {
                    flag = 1;
                }
                if(i < H-1 && canvas[i+1][j] == '#') {
                    flag = 1;
                }
                if(j > 0 && canvas[i][j-1] == '#') {
                    flag = 1;
                }
                if(j < W-1 && canvas[i][j+1] == '#') {
                    flag = 1;
                }
            } else {
                flag = 1;
            }
            if(flag == 0) {
                goto LOOP_OUT;
            }
        }
    }
LOOP_OUT:

    if(i == H && j == W) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
