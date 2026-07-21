#include <stdio.h>
 
int main (void){
    int score, bscore = -1, a_c;
    int h;
    int i, j, before;
    int del = -1;
    int f, e;
    while(1)
    {
        score = 0;
        bscore = -1;
        scanf("%d", &h);
        int a[h][5];
        if (h == 0) break;
        for (i = 0; i < h; i++) {
            a_c = 0;
            for (j = 0; j < 5; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        while (score != bscore) {
            bscore = score;
            for (i = 0; i < h; i++){
                a_c = 0;
                del = -1;
                for (j = 0; j < 5; j++) 
                {
                    //printf("%d ", a_c);
                    if (j == 0) {
                        before = a[i][j];
                        a_c++;
                        f = j;
                    } else if (before == a[i][j]) {
                        a_c++;
                        //printf("%d ", a_c);
                    } else {
                        if (a_c >= 3 && before != -1) {
                            score += before * a_c;
                            del = before;
                            e = j;
                        }
                        a_c = 1;
                        before = a[i][j];
                        if(j <= 2){
                        	f = j;
                        }
                    }
                    if(j == 4) {
                        if (a_c >= 3 && before != -1) {
                            score += before * a_c;
                            del = before;
                            e = j;
                        }
                        a_c = 0;
                    }
                }
                for (j = 0; j < 5; j++) {
                    if(a[i][j]==del && j >= f && j <= e){
                        a[i][j]=-1;
                    }
                }
 
            }
 
 
 
/*
            printf("\n");
            for (i = 0; i < h; i++){
                for (j = 0; j < 5; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
*/
 
 
            int flag = 0, i_;
                for(j = 0; j < 5; j++){
                    flag = 0;
                    for(i = h-1; i >= 0; i--){
                        if(a[i][j] == -1){
                            int k = i - 1;
                            while(k >= 0){
                                if(a[k][j] != -1){
                                    a[i][j] = a[k][j];
                                    a[k][j] = -1;
                                    break;
                                }
                                k--;
                            }
                        }
                    }
                }
 
/*
            printf("\n");
            for (i = 0; i < h; i++){
                for (j = 0; j < 5; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
*/
 
        }
        printf("%d\n", score);
    }
    return 0;
}
