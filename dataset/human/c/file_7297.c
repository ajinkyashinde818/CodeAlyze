#include<stdio.h>

int main(){
    int h, w, k;
    scanf("%d%d%d", &h, &w, &k);
    int t[h][w];
    int x = 1;
    for(int i=0; i<h; i++){
        char s[w+1];
        scanf("%s", s);
        for(int j=0; j<w; j++){
            if(s[j] == '.'){
                t[i][j] = -1;
            }else{
                t[i][j] = x;
                x++;
            }
        }
    }
    for(int i=0; i<h; i++){
        int buf = 0, id = -1;
        for(int j=0; j<w; j++){
            if(t[i][j] != -1){
                id = t[i][j];
                for(int l=buf; l<=j; l++){
                    t[i][l] = id;
                }
                buf = j+1;
            }
        }
        if(buf < w && id != -1){
            for(int l = w-1; l>=0; l--){
                if(t[i][l] != -1){
                    break;
                }
                t[i][l] = id;
            }
        }
    }
    if(t[0][0] == -1){
        int buf = 0;
        for(int i=0; i<h; i++){
            if(t[i][0] != -1){
                buf = i;
                break;
            }
        }
        for(int i=buf-1; i>=0; i--){
            for(int j=0; j<w; j++){
                t[i][j] = t[i+1][j];
            }
        }
    }
    for(int i=1; i<h; i++){
        if(t[i][0] == -1){
            for(int j=0; j<w; j++){
                t[i][j] = t[i-1][j];
            }
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            printf("%d", t[i][j]);
            if(j < w-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }

    return 0;
}
