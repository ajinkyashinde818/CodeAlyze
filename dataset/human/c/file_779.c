#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define int64 long long

int main()
{
int64 dd, gg, min = LLONG_MAX, xx;//LLong:longlong max
scanf("%lld %lld", &dd, &gg);
int64 pp[dd], cc[dd], score[dd];
for(int64 ii = 0;ii < dd;ii++){
 scanf("%lld %lld", &pp[ii], &cc[ii]);
 score[ii] = pp[ii] * (ii + 1) * 100 + cc[ii];//ボーナスあり
}
int64 tmp, kosu;
for(int64 bit = 0;bit < (1 << dd);bit++){//2^ddまで
 tmp = 0;
 kosu = 0;
 for(int64 ii = 0;ii < dd;ii++){
  if(bit & (1 << ii)){//2^(ii-1)の数字を比べる
   tmp += score[ii];//完全に解く
   kosu += pp[ii];
}}
if(tmp < gg){
for(int64 ii = dd - 1;ii >= 0;ii--){
 if(!(bit & (1 << ii))){//点数高いものから：上から
  xx = (gg - tmp) / ((ii + 1) * 100);
 //残り点数/配点：残り問題数
 if((gg - tmp) % ((ii + 1) * 100))xx++;
 //割り切れないときの調整
 if(xx > pp[ii])break;//ボーナスもらえるはず、おかしい
  tmp += xx * (ii + 1) * 100;//中途半端に解いた時
  kosu += xx;
 break;
}}}
		
if(min > kosu && tmp >= gg){
 //目標点数以上且つ個数(初期値最大)を小さめに
 min = kosu;
}}
printf("%lld\n", min);

return 0;}
