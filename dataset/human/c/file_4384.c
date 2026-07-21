#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(){
    int n, d[100][2], i, j, flag = 1;

    scanf("%d", &n);

    for(i = 0;i < n;i++){
        for(j = 0;j < 2;j++){
            scanf("%d", &d[i][j]);
        }
    }

    for(i = 0;i < n - 2;i++){
        if(d[i][0] == d[i][1] && d[i + 1][0] == d[i + 1][1] && d[i + 2][0] == d[i + 2][1]){
            flag = 0;
        }
    }
    if(flag) puts("No");
    else puts("Yes");

    return 0;
}
