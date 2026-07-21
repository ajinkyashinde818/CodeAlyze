#include <stdio.h>

int main(void){
    int h;
    int i, j, k;

    while(1){
        scanf("%d", &h);
        if(h == 0){
            break;
        }

        int puzzle[h][5];
        for(i = 0; i < h; i++){
            for(j = 0; j < 5; j++){
                scanf("%d", &puzzle[i][j]);
            }
        }
        
        int flag;
        int count;
        int sum = 0;
        int point = -1;

        while(point != 0){
            /* for(i = 0; i < h; i++){
                for(j = 0; j < 5; j++){
                    printf("%d " ,puzzle[i][j]);
                }
                printf("\n");
            }
            printf("\n"); */

            point = 0;
            for(i = 0; i < h; i++){
                for(j = 0; j < 5; j++){
                    if(j == 0){
                        flag = puzzle[i][j];
                        count = 1;
                    }

                    else{
                        if(flag == puzzle[i][j]){
                            count++;
                            if(j == 4){
                                point += flag * count;
                                for(k = 5 - count; k <= 4; k++){
                                    puzzle[i][k] = 0;
                                }
                            }
                        }
                        else{
                            if(j <= 2){
                                flag = puzzle[i][j];
                                count = 1;
                            }
                            else{
                                if(count >= 3){
                                    point += flag * count;
                                    for(k = j - count; k < j; k++){
                                        puzzle[i][k] = 0;
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
            }

            for(i = h - 1; i > 0; i--){
                for(j = 0; j < 5; j++){
                    if(puzzle[i][j] == 0){
                        k = i - 1;
                        while(1){
                            if(puzzle[k][j] != 0){
                                puzzle[i][j] = puzzle[k][j];
                                puzzle[k][j] = 0;
                                break;
                            }
                            if(k == 0){
                                break;
                            }
                            k--;
                        }
                    }
                }
            }

            sum += point;
        }

        printf("%d\n", sum);
    }

    return 0;
}
