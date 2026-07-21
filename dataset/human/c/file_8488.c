#include<stdio.h>
#include<string.h>
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)
#define rep2(i,j,n) for(int (i)=(j); (i) < (n); (i)++)
int h, x[10][5];
void input(){
    rep(i,h) rep(j,5){
        scanf("%d",&x[i][j]);
    }
}
int cal(){
    int chain, flag, score=0;
    while(1){
        flag=0;
        for(int i=h-1; i>-1; i--){//i列目の連鎖
            for(int j=0; j<3; j++){
                chain=1;
                for(int k=j+1; k<5; k++){
                    if(x[i][j]!=-1 && x[i][j]==x[i][k]) chain++;
                    else break;
                }
                if(chain>2){
                    flag=1; score+=x[i][j]*chain;
                    for(int k=j; k<j+chain; k++){
                        x[i][k]=-1;
                    }
                    break;
                }
            }
        }
        if(flag==0)break;
        
        for(int i=h-1; i>0; i--){
            for(int j=0; j<5; j++){
                for(int k=i-1; k>=0; k--){
                    if(x[i][j]==-1 ) {if(x[k][j]!=-1){
                        x[i][j]=x[k][j];
                        x[k][j]=-1;
                    }}
                    else break;
                }
            }
        }
        
        /*rep(i,h) {
            rep(j,5){
                printf("%2d ",x[i][j]);
            }
            puts("");
        }puts("");*/
    }
    return score;
}
int main(void){
    int score=0;
    while(1){
        scanf("%d",&h);
        if(h==0) break;
        input();
        /*printf("入力\n");
        rep(i,h) {
            rep(j,5){
                printf("%2d ",x[i][j]);
            }
            puts("");
        }puts("");*/
        printf("%d\n",cal());
    }
    return 0;
}
