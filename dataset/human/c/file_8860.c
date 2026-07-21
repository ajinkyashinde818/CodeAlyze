#include <stdio.h>

int main(){
    int h, w, i, j, k, cnt;
    char s[50][51];
    int p[4] = {-1, 0, 0, 1};
    int q[4] = { 0,-1, 1, 0};

    scanf("%d %d", &h, &w);

    for(i=0; i<h; i++){
        scanf("%s", s[i]);
    }

    for(i=0; i<h; i++){
        for(j=0; j<w; j++){
            if(s[i][j] == '#'){
                cnt=0;
                for(k=0; k<4; k++){
                    if(s[i+p[k]][j+q[k]] == '#')
                        cnt++;
                }
                if(cnt == 0){
                    printf("No\n");
                    return 0;
                }
            }
        }
    }

    printf("Yes\n");

    return 0;
}
