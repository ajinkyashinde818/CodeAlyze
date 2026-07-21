#include<stdio.h> 

int main()
{
    long a, b, tmp;
    long r,x;
    scanf("%ld%ld", &a, &b);

    if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
  x = a*b;
  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  /* 最小公倍数を出力 */
  printf("%ld\n", x/b);
 
  return 0;
}
