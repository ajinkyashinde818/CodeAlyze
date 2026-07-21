#include <stdio.h>

int main(void){
    int h, w, flag = 0, f[50], plag = 0;
    char v;
    scanf("%d%d", &h, &w);
    getchar();
    for(int i = 0; i < 50; i++)
        f[i] = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            v = getchar();
            // printf("start>> i: %d j: %d flag: %d plag: %d f[j]: %d f[j-1]: %d\n",i, j, flag, plag, f[j], f[j-1]);
            if(v == '#'){
                // printf("In Black\n");
                plag = 0;
                if(flag == 0){
                    if(f[j] == 0){
                        plag = 1;
                        if(j == w - 1)
                            f[j] = 2;
                        else
                            f[j] = 1;
                    }
                    else
                        f[j] = 1;
                }
                else
                    f[j] = 1;
                flag = 1;
            }
            else{
                // printf("In White\n");
                if(plag == 1){
                    if(i == h - 1){
                        printf("No\n");
                        // printf("Status: ENDLINE\n");
                        return 0;
                    }
                    if(j != 0)
                        f[j - 1] = 2;
                }
                if(f[j] == 2){
                    printf("No\n");
                    // printf("Status: TAKECARE\n");
                    return 0;
                }
                f[j] = 0;
                flag = 0;
                plag = 0;
            }
            // printf("end>> i: %d j: %d flag: %d plag: %d f[j]: %d f[j-1]: %d\n",i, j, flag, plag, f[j], f[j-1]);
        }
        getchar();
        flag = 0;
        plag = 0;
    }
    printf("Yes\n");
    return 0;
}
