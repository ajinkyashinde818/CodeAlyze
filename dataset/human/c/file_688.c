#include <stdio.h>
#include <string.h>
int main(void){
    int n,m;
    scanf("%d %d",&n,&m);
    char data1[n][n+1];
    char data2[m][m+1];
    int i,j,k,l;
    for(i = 0;i<n;i++){
        scanf("%s",data1[i]);
    }
    for(i = 0;i<m;i++){
        scanf("%s",data2[i]);
    }
    int flag = 0;
    for(i = 0;i<n;i++){
        for(j = 0;j<n;j++){
            if(data1[i][j] == data2[0][0]){
                for(k = 0;k<m;k++){
                    for(l = 0;l<m;l++){
                            // printf("%d %d %d %d\n",i+k,j+l,k,l);
                            // printf("%c %c\n",data1[i+k][j+l],data2[k][l]);
                        if(data1[i + k][j + l] != data2[k][l]){
                        // printf("d1%c\n",data1[i+k][j+l]);
                        // printf("d2%c\n",data2[k][l]);
                        // printf("test\n");
                        flag = 1;
                            break;
                        }
                        if(l == m-1 && k == m-1){
                            printf("Yes\n");
                            return 0;
                        }
                    }
                    if(flag != 0){
                        flag = 0;
                        break;
                    }
                }
            }
        }
    }
    printf("No\n");
    return 0;
}
