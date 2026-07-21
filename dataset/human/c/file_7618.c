//複数の入力ケースの表示

#include <stdio.h>

int main(){

  int x = 0;        //初期化
  int i = 1;        //ケース1から

  while(1){
    scanf("%d", &x);

    if(x < 0 || x > 10000)
        {
            //エラーメッセージを表示して終了する
            printf("Invalid Input\n");
            return 0;
        }


    if(x != 0){
      printf("Case %d: %d\n", i, x);
      i += 1;
    }else{          //入力が0で終了
      break;
    }
  }

  return 0;
}
