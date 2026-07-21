//Twitter@KonoLv1 2020年春卒で現在就職活動中！
 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
 
int main(void){
    int i,j;            //  ループ文に使用
    int x,y,z;
    int count1,count2,count;   //  カウント用に使用
    int box[256] = {};
    int box2[256] = {};
    int box3[256] = {};
    char s[200001] = {};        //  文字列
    char s2[200001] = {};        //  文字列
    int a,b,c,n,save;
    a = b = c = i = 0;
    save = -999;
    int mode = 0;
    count = count1 = count2 = 0;
 
    //  入力処理
    
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d",&box[i]);
    }
    for (i = 0; i < n; i++){
        scanf("%d",&box2[i]);
    }
    for (i = 0; i < n - 1; i++){
        scanf("%d",&box3[i]);
    }
 
    //  計算処理
    
    for (i = 0; i < n; i++){
        j = box[i];
        count = count + box2[j - 1];
        if (save + 1 == j){
            count = count + box3[save - 1];
        }
        save = j;
    }
  
    //  出力処理
 
 
    printf("%d",count);

 
}
