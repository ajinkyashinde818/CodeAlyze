#include<stdio.h>
int main(void){
  int r,g,b,n,cnt = 0;
  scanf("%d %d %d %d",&r,&g,&b,&n);
  for(int i = 0;i <= n / r;i++){
    for(int j = 0;j <= n / g;j++){
      int k = n - i * r - j * g;
      if(k > -1 && k % b < 1){
        cnt++;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}
