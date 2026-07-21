#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){

    char canvas[52][52];
    int h = 0;
    int w = 0;
    int loop_h = 0;
    int loop_w = 0;
    int flag = 0;
    char strin[52];

    memset(canvas, 0x00, sizeof(canvas));

    scanf("%d%d", &h, &w);
    while ('\n' != getchar());
    for (loop_h = 0; loop_h < h; loop_h++){
        memset(strin, 0x00, sizeof(strin));
        fgets(strin, 52, stdin);

        for (loop_w = 0; loop_w < w; loop_w++){
            canvas[loop_h + 1][loop_w + 1] = strin[loop_w];
        }
    }

    for (loop_h = 1; loop_h < h + 1; loop_h++){
        for (loop_w = 1; loop_w < w + 1; loop_w++){
            if ('#' == canvas[loop_h][loop_w]){

                if (('#' != canvas[loop_h - 1][loop_w])
                    && ('#' != canvas[loop_h + 1][loop_w])
                    && ('#' != canvas[loop_h][loop_w - 1])
                    && ('#' != canvas[loop_h][loop_w + 1])){
                    flag = 1;
                    break;
                }
            }
        }
    }

    if (0 == flag){
        printf("Yes");
    }
    else{
        printf("No");
    }

    return 0;
}
