#include <stdio.h>

int main(void)
{
    int H;
    int board[10][5];
    int score;
    int n, m;
    int flag;
    int i, j, k, l;

    while (1){
        scanf("%d", &H);
        if (H == 0){
            break;
        }
        for (i = 0; i < H; i++){
            for (j = 0; j < 5; j++){
                scanf("%d", &board[i][j]);
            }
        }
        
        score = 0;
        
        do {
            flag = 0;
            
            for (i = 0; i < H; i++){
                n = 0;
                m = board[i][2];
                if (m == 0){
                    continue;
                }
                for (j = 0; j < 5; j++){
                    if (board[i][j] == m){
                        n++;
                    }
                }
                if (n == 3){
                    if (board[i][1] != m && board[i][3] != m){
                        continue;
                    }
                    if (board[i][1] != m && board[i][4] != m){
                        continue;
                    }
                    if (board[i][0] != m && board[i][3] != m){
                        continue;
                    }
                }
                    
                if (n >= 3){
                    if (n == 4 && (m != board[i][1] || m != board[i][3])){
                        n = 3;
                        if (m == board[i][1]){
                            board[i][0] = board[i][1] = board[i][2] = 0;
                        }
                        else {
                            board[i][2] = board[i][3] = board[i][4] = 0;
                        }
                    }
                    else {
                        for (j = 0; j < 5; j++){
                            if (board[i][j] == m){
                                board[i][j] = 0;
                            }
                        }
                    }
                    score += (m * n);
                    flag = 1;
                }
            }
#if 0
printf("↓↓↓↓↓↓↓\n");
for (i = 0; i < H; i++){
    for (j = 0; j < 5; j++){
        printf("%d ", board[i][j]);
    }
    printf("\n");
}
#endif
            if (flag == 1){
                for (i = H - 1; i >= 0; i--){
                    for (j = 0; j < 5; j++){
                        if (board[i][j] == 0){
                            for (k = i - 1; k >= 0; k--){
                                if (board[k][j] != 0){
                                    board[i][j] = board[k][j];
                                    board[k][j] = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
#if 0            
printf("*************\n");
for (i = 0; i < H; i++){
    for (j = 0; j < 5; j++){
        printf("%d ", board[i][j]);
    }
    printf("\n");
}
#endif
        } while (flag == 1);
        
        printf("%d\n", score);
    }
    
    return (0);
}
