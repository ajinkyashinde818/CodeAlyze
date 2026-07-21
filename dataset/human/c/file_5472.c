#include<stdio.h>

int main(){
  int W,H,N;
  int i;
  int X[1001]={};
  int Y[1001]={};
  int ans=0;
  int dx,dy;

  scanf("%d%d%d",&W,&H,&N);
  for(i=0;i<N;i++)
    scanf("%d%d", &X[i],&Y[i]);

  for(i=1;i<N;i++){
    dx=X[i]-X[i-1];
    dy=Y[i]-Y[i-1];
    if(dx>=0&&dy>=0){
      if(dx>dy) ans+=dx;
      else ans+=dy;
    }
    else if(dx<=0&&dy<=0){
      if(-dx>-dy) ans += (-dx);
      else ans += (-dy);
    }
    else if(dx>0&&dy<0) ans+= (dx-dy);
    else ans+= (dy-dx);
  }
  printf("%d\n",ans);

  return 0;
}
