#include<stdio.h>

int main(){
  int R = 0;
  int G = 0;
  int B = 0;
  int N = 0;
  int r = 0;
  int g = 0;
  int b = 0;
  int cnt = 0;
  int hoge = 0;
  scanf("%d",&R);
  scanf("%d",&G);
  scanf("%d",&B);
  scanf("%d",&N);
  for(r = 0;r <= N/R;r++){
    for(g = 0;g <= N/G;g++){
      hoge = N-(r*R+g*G);
      if(hoge >= 0 && hoge % B == 0){
        cnt++;
      }
    }
  }
  printf("%d",cnt);
  return 0;
}
