#include <stdio.h>
#include <stdlib.h>
#define COL 5

//ステップ1,2,3を一回実行する関数
int solve_1_time(int ** ban, int H) {
    int i, j, k;
    int score = 0;
    //消滅の過程
    for (i = H - 1; i >= 0; i--) {
        int same_num = 1;
        int max_id = -1;
        int max = 0;
        for (j = 1; j < COL; j++) {
            if (ban[i][j] == ban[i][j-1] && ban[i][j] != 0) {
                same_num++;
                if (same_num > max) {
                    max = same_num;
                    max_id = j;
                }
            } else {
                same_num = 1;
            }
        }
        if (max > 2) score += max * ban[i][max_id];
        if (max > 2) {
            for (k = max_id+1-max; k <= max_id; k++) {
                ban[i][k] = 0;
            }
        }
    }
    //落下の過程
    for (i = H - 2; i >=0; i--) {
        for (j = 0; j < COL; j++) {
            for (k = 1; i + k < H; k++) {
                if (ban[i+k][j] != 0) break;
            }
            if (k > 1) {
                ban[i+k-1][j] = ban[i][j];
                ban[i][j] = 0;
            }
        }
    }
    return score;
}

int main(void) {
    int H;
    int i, j;
    int **ban;
    while (1) {
        scanf("%d", &H);
        if (H == 0) break;
        //盤の読み込み
        ban = (int **)malloc(sizeof(int*) * H);
        for (i = 0; i < H; i++) {
            ban[i] = (int *)malloc(sizeof(int) * COL);
        }
        for (i = 0; i < H; i++) {
            for (j = 0; j < COL; j++) {
                scanf("%d", &ban[i][j]);
            }
        }
        
        int score;
        int tot = 0;
        do {
            score = solve_1_time(ban, H);
            tot += score;
        } while (score != 0);
        
        printf("%d\n", tot);
        
        //free
        for (i = 0; i < H; i++) {
            free(ban[i]);
        }
        free(ban);
    }
    return 0;
}
