#include<stdio.h>

int main(void){
    int i,j,k,l,f,N,M;

    char a[50][50],b[50][50];

    scanf("%d %d",&N,&M);

    for(i = 0;i < N;i++)
        scanf("%s",&a[i][0]);

    for(i = 0;i < M;i++)
        scanf("%s",&b[i][0]);

    for(i = 0;i < N - M + 1;i++)
        for(j = 0;j < N - M + 1;j++){
            f = 1;
            for(k = 0;k < M;k++){
                for(l = 0;l < M;l++){
                    if(a[i + k][j + l] != b[k][l])
                        f = 0;
                }
            }
            if(f == 1){
                printf("Yes\n");
                return 0;
            }
        }
    printf("No\n");
    return 0;
}
