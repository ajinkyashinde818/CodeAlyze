#include <stdio.h>
#include <stdlib.h>

int main(){
    int H, W, K_max;
    
    scanf("%d%d%d", &H, &W, &K_max);

    char **s = (char **) malloc(sizeof(char *) * H);

    for(int i = 0; i < H; i ++){
        s[i] = (char *) malloc(sizeof(char) * (W + 1));

        scanf("%s", s[i]);
    }
    int **ans = (int **) malloc(sizeof(int *) * H);
    
    for(int i = 0; i < H; i ++){
        ans[i] = (int *) malloc(sizeof(int) * W);

        for(int j = 0; j < W; j ++){
            ans[i][j] = -1;
        }
    }
    int K = 1;
    int s_i = 0;
    int s_j = 0;
    int e_i = 0;
    int found = 0;

    for(int i = 0; i < H; i ++){
        for(int j = 0; j < W; j ++){
            if(found == 0){
                if(s[i][j] == '#'){
                    found = 1;

                    int ii, jj;

                    for(ii = i + 1; ii < H; ii ++){
                        for(jj = 0; jj < W; jj ++){
                            if(s[ii][jj] == '#'){
                                break;
                            }
                        }
                        if(jj < W){
                            break;
                        }
                    }
                    if(ii == H){
                        e_i = H - 1;
                    }else{
                        e_i = ii - 1;
                    }
                }
            }
            if(found == 1){
                if(j + 1 == W){
                    int e_j = W - 1;

                    for(int ii = s_i; ii <= e_i; ii ++){
                        for(int jj = s_j; jj <= e_j; jj ++){
                            ans[ii][jj] = K;
                        }
                    }
                    K ++;
                    s_i = i + 1;
                    s_j = 0;
                    found = 0;
                }else if(s[i][j + 1] == '#'){
                    int e_j = j;

                    for(int ii = s_i; ii <= e_i; ii ++){
                        for(int jj = s_j; jj <= e_j; jj ++){
                            ans[ii][jj] = K;
                        }
                    }
                    K ++;
                    s_j = j + 1;
                    found = 0;
                }
            }
        }
    }
    for(int i = 0; i < H; i ++){
        for(int j = 0; j < W; j ++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}
