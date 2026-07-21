#include <stdio.h>

int main(){
  int r,g,b,n;
  scanf("%d%d%d%d",&r,&g,&b,&n);
  int answer = 0;
  int bin;
  for(int i = 0; i <= n/r; ++i){
    for(int j = 0; j <= n/g; ++j){
      bin = n - i*r - j*g;
      if(bin < 0) break;
      if((bin % b) == 0) answer++;
    }
  }
  
  printf("%d\n",answer);
  return 0;
}
