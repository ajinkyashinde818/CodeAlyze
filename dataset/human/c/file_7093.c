#include <stdio.h>
int H,W,h,w;
int main(){
  for(;~scanf("%d%d",&H,&W);){
    for(h=0;H-h++;){
      for(w=0;W-w++;printf("%c",w%2-h%2?'.':'#'));
      printf("\n");
    }
    if(W)printf("\n");
  }
  return 0;
}
