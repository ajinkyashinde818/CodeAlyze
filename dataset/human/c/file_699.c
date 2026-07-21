#include<stdio.h>

int main(void){
    int n,m;
    scanf("%d %d",&n,&m);
    char pic_a[n][n];//[y][x]
    char pic_b[m][m];
    for(int i = 0;i < n;i++)scanf("%s",pic_a[i]);
    for(int i = 0;i < m;i++)scanf("%s",pic_b[i]);
    int maxoffset = n-m;
    int flag = 0;
    for(int offx = 0;offx <= maxoffset;offx++)for(int offy = 0;offy <= maxoffset;offy++){
        flag = 0;
        for(int i = 0;i < m;i++)for(int j = 0;j < m;j++)if(pic_a[i+offx][j+offy] != pic_b[i][j])flag = 1;
        if(!flag){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
