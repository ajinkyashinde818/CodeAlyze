#include <stdio.h>

int main(){
    int H,W;
    scanf("%d %d",&H,&W);
    char can[H][W+1];
    for(int i=0;i<H;i++){
        for(int j=0;j<=W;j++){
            scanf("%c",&can[i][j]);
        }
    }
    for(int i=0;i<H;i++){
        for(int j=1;j<=W;j++){
            if(can[i][j]==35){
                if(j==1||i==0)continue;
                if(can[i-1][j]==35||can[i][j-1]==35)continue;
                if(j==W||i==H-1)continue;
                if(can[i][j+1]==35||can[i+1][j]==35)continue;
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}
