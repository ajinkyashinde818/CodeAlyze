#include <stdio.h>

int min(int a, int b){
  if( a > b)return b;
  return a;
}

int zero(int a){
  if( a < 0)return 0;
  return a;
}
int main(int argc, char const *argv[]) {
  int k,s;
  int x,y,z;
  int i,j,l;
  int count=0;
  scanf("%d %d", &k,&s);

  for(i = zero(s - 2*k);i<=k;i++){
    //if( s - i > 2*k)continue;
    if( i > s)break;
    for(j = zero(s - k - i);j<= min(k, s-i) ;j++){
      //if( s - i - j > k)continue;
      if( i + j > s)break;
      if( s - i - j <= k )count++;
      /*
      for(l = 0;l <= min(k, s - i -j);l++){
        if(s == i + j + l){
          count++;
          break;
        }
      }
      */
    }
  }
  printf("%d\n",count );
  return 0;
}
