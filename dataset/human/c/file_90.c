#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//関数宣言
//int func(int x, int y);

int main(void){

  //スカラー入力
  int R,G,B,N;

  scanf("%d %d %d %d", &R, &G, &B, &N);

  int X,Y,Z;

  if(R>=G && R>=B){
    X=R;
    if(G>=B){
      Y=G;
      Z=B;
    }else{
      Y=B;
      Z=G;
    }
  }else if(G>=B && G>=R){
    X=G;
    if(B>=R){
      Y=B;
      Z=R;
    }else{
      Y=R;
      Z=B;
    }
  }else{
      X=B;
      if(R>=G){
        Y=R;
        Z=G;
      }else{
        Y=G;
        Z=R;
    }
   }

  /* printf("%d %d %d\n", X,Y,Z); */

  int Xmax,Ymax,ans;

  ans = 0;
  Xmax = N/X;

  for(int i=0; i<=Xmax; i++){
    Ymax = (N-X*i)/Y;
    for(int j=0; j<=Ymax; j++){
      /* printf("%d %d %d\n", i, j, ) */
      if((N-X*i-Y*j)%Z == 0){
        ans++;
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
