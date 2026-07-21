#include <stdio.h>
  
void MCXI(char* mcxi,int num){                         //十進数をMCXI文字列に変換
  if(num>=1000){
    if(num>=2000)*(mcxi++)=(num/1000)+'0';             //千の位の値が2以上の場合　*mcxiの値が千の位の値と等しくなるまでインクリメント
    *(mcxi++)='m';                                     //千の位の値を表す数字の後ろにmを書き込み
    num%=1000;                                         //1000で割った余りをnumに更新　次のステップに進む
  }
  if(num>=100) {                                       //百の位の変換　理論は千の位と同じ
    if(num>=200)*(mcxi++)=(num/100)+'0';
    *(mcxi++)='c';
    num%=100;
  }
  if(num>=10) {                                        //十の位の変換　理論は千の位と同じ
    if(num>=20)*(mcxi++)=(num/10)+'0';
    *(mcxi++)='x';
    num%=10;
  }
  if(num>=1) {                                         //一の位の変換　理論は千の位と同じ
    if(num>=2)*(mcxi++)=(num/1)+'0';
    *(mcxi++)='i';
    num%=1;
  }
  *mcxi=0;                                             //*mcxiの値を0に初期化する
}
  
int decimal(const char* mcxi) {
  const char* nowp=mcxi;
  int num=1;
  int decimal=0;
  for(;*nowp;nowp++) {
    switch(*nowp) {
    case 'm':
      decimal+=1000*num;                               //返り値decimalに千の位の値を1000倍して加算
      num=1;                                           //numを1にリセット
      break;
    case 'c':                                          //百の位の変換　理論は千の位と同じ
      decimal+=100*num;
      num=1;
      break;
    case 'x':                                          //十の位の変換　理論は千の位と同じ
      decimal+=10*num;
      num=1;
      break;
    case 'i':                                          //一の位の変換　理論は千の位と同じ
      decimal+=1*num;
      num=1;
      break;
    default:
      if(isdigit(*nowp))num=*nowp-'0';                 //各位に前置きされた数字をnumに読み込み
    }
  }
  return decimal;                                      //変換された十進数を返り値として返す
}
  
int main(void) {
  int num,i;
  char MCXI_1[100],MCXI_2[100];
  
  struct{                                              //出力用の構造体配列
    char sum[100];
  }SUM[9999];
  
  scanf("%d",&num);                                    //先頭nを読み込み
  
  for(i=0;i<num;i++){
    scanf("%s%s",MCXI_1,MCXI_2);                       //2つのMCXI文字列を読み込み
    MCXI(SUM[i].sum,decimal(MCXI_1)+decimal(MCXI_2));  //2つのMCXI文字列をdecimal関数を使って十進数に変換
  }                                                    //MCXI関数を使ってMCXI文字列に変換　変換結果をi番目構造体配列に入れる
  
  for(i=0;i<num;i++){
    printf("%s\n", SUM[i].sum);                        //出力
  }
  
  return 0;
}
