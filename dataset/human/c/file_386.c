#include<stdio.h>
int main(void){
    int N;//会員のコンテスト参加回数
    int dispR;//表示レーティング
    int inteR;//内部レーティング
    //入力
    scanf("%d %d",&N,&dispR);

    //エラー排除
    if(N>=1 && N<=100 && dispR>=0 && dispR<=4111){
        //処理
        if(N >= 10){
            inteR = dispR;
        }else{
            inteR = dispR + 100*(10 - N);
        }
    
        //出力
        printf("%d",inteR);
    }
    return 0;
}
