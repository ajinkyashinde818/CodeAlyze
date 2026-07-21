#include <stdio.h>

int main(void){
    int n, m;
    char p;
    int tempFlag = 1, flag = 0;
    scanf("%d %d\n", &n, &m);
    char a[n][n+1], b[m][m+1];
    //printf("%d,%d",n,m);
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= n;j++){
            scanf("%c", &a[i][j]);
            //printf("a[i][j] = %c\n",a[i][j]);
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j <= m;j++){
            scanf("%c", &b[i][j]);
            //printf("b[i][j] = %c\n",b[i][j]);
        }
    }

    /*for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%c\n",a[i][j]);
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++){
            printf("%c\n",b[i][j]);
        }
    }*/

    for(int i = 0;i <= n - m;i++){
        for(int l = 0;l <= n - m;l++){
            tempFlag = 1;
            for(int j = 0;j < m;j++){
                for(int k = 0;k < m;k++){
                    if(a[i+j][l+k] == b[j][k]){
                        tempFlag = tempFlag && 1;
                        //printf("match : ");
                        //printf("%c,%c\n",b[j][k],a[i][l]);
                    }else{
                        tempFlag = tempFlag && 0;
                        //printf("NotMatch : %c,%c\n",b[j][k],a[i][l]);
                    }
                }
            }
            if(tempFlag == 1){
                flag = 1;
                break;
            }
            //printf("comp\n");
        }
        if(tempFlag == 1){
                flag = 1;
                break;
        }
        //printf("comp\n");

    }
    printf("%s", (flag == 1) ? "Yes\n" : "No\n");
    //printf("%d", 1 && 0);
    return 0;
}
