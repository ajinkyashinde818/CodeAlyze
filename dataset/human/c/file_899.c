#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define WDSIZE 10000000
typedef long long ll;
#define BUFSIZE 1000000000000

ll n;
int count = 0;
int divisor[WDSIZE] = {0};

//その約数が使われたことがあるか確認

int used_check(ll b){
  for(int i = 0;i < BUFSIZE; i++){
    if(divisor[i] == 0) break;
    if(divisor[i] == b) return 1;
  }
  return 0;
}

///素数判定
int prime(ll num){
  if(num == 1) return 1;
  for(ll i = 2;i <= sqrt(num);i++){
    if(num % i == 0){
      return 1;
    }
  }
    return 0; //素数なら０を返す
}


int frag = 0 ; //塁乗だったら０　違ったら　１にする
int rem; //一時的に割り切れる数を記憶
///素数の累乗かcheck

int conform_check(ll given){
  frag = 0;
  for(ll i = 2;i <= sqrt(given);i++){
    if(given % i == 0 && prime(i) == 0){
       rem = i;
       break;
     }
   }
  while(given > 1){

    if(given % rem == 0){
      given = given/rem;
    }else{
      frag = 1;
      break;
    }
  }
  if(frag == 1) return 0;
  else  return 1;
}

int flag_fin; //１だったらもう操作できない　終了条件判定


//入力した値を　まだ割ったことのない数かつ、素数or素数の累乗で割る関数

int fact(ll a){
  if(prime(a) == 0 && used_check(a) == 0){
    divisor[count] = a;
    count++;
    return 0;
  }
  for(ll i = 2;i <= a;i++){
    if(a % i == 0){
      if(used_check(i) == 1) continue; //使われてない確認
      else if(prime(i) == 0 || conform_check(i) == 1){ //素数か素数の累乗ならOK
        divisor[count] = i;///割った数を記憶　割るのは下のcal内
        count++;
        return 0;
      }
    }
  }
  flag_fin = 1;
  return 0;
}


int cal(ll given_number){
  fact(given_number);
  if(divisor[count - 1] == 0 || prime(given_number) == 0 || flag_fin == 1)
  return 0;
  cal(given_number/divisor[count - 1]);
}


int main(void){
  scanf("%lld",&n);
  if(prime(n) == 0){
    printf("1");
    exit(0);
  }
  cal(n);
  printf("%d",count);

  return 0;
}
