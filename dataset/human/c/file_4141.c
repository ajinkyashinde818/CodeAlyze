#include<stdio.h>

int cmpt_gcd(int large, int small){
  int r = large%small;
  if(r==0){
    return small;
  }
  cmpt_gcd(small, r);
}

int main(){
  int a, b, k, r, cnt=0, kth_gcd;
  scanf("%d %d %d", &a, &b, &k);
  
  if(a<b){
    int tmp = a;
    a = b;
    b = tmp;
  }
  r = cmpt_gcd(a, b);
//  printf("%d\n",r);
  
  for(int i=r; cnt<k; i--){
    if(a%i==0 && b%i==0){
      cnt++;
      kth_gcd = i;
//      printf("cnt %d  i %d\n",cnt, i);
    }
  }
  
  printf("%d", kth_gcd);

  return 0;
}
