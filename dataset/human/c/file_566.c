#include <stdio.h>

#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int main(void){
    char ptnA[50][50];
    char ptnB[50][50];
    char tmp[51];
    int n,m,flg;
    
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++){
        scanf("%s", tmp);
        for (int j=0; j<n;j++){
            ptnA[j][i] = tmp[j];
        }
    }
    for (int i=0; i<m; i++){
        scanf("%s", tmp);
        for (int j=0; j<m;j++){
            ptnB[j][i] = tmp[j];
        }
    }
    
    flg = 0;
    for (int x=0; x <= n-m; x++){
        for (int y=0; y <= n-m; y++){
            int matched = 1;
            for (int w=0; w<m; w++){
                for (int h=0; h<m; h++){
                    if (ptnA[x+w][y+h] != ptnB[w][h]){
                        matched = 0;
                        break;
                    }
                }
                if (!matched) break;
            }
            if (matched){
                flg = 1;
                break;
            }
        }
        if (flg) break;
    }
    
    puts(flg?"Yes":"No");
    return 0;
}
