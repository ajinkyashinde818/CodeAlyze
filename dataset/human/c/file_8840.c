#include<stdio.h>

int main(void){
        int h, w, fie[52][52], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for(int i=0; i<52*52; i++) fie[i/52][i%52] = 0;
        scanf("%d %d", &h, &w);

        for(int i=1; i<=h; i++){
                char s[w+1];
                scanf("%s", s);
                for(int j=1; j<=w; j++){
                        fie[i][j] = (s[j-1]=='#');
                }
        }

        int yes = 1;
        for(int i=1; i<=h; i++){
                for(int j=1; j<=w; j++){
                        if(!fie[i][j]) continue;
                        int can = 0;
                        for(int k=0; k<4; k++){
                                if(fie[i+dx[k]][j+dy[k]]) can = 1;
                        }
                        if(!can) yes = 0;
                }
        }

        if(yes) puts("Yes");
        else puts("No");
        return 0;
}
