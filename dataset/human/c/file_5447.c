#include<stdio.h>
int main(){
  int n,x,y,dx,dy,bx,by,s=0,f,min;
  scanf("%*d %*d %d",&n);
  scanf("%d %d",&bx,&by);
  while(--n){
    scanf("%d %d",&x,&y);
    dx=x-bx;
    dy=y-by;
    bx=x;
    by=y;
    if(dx*dy>0)f=1;
    else       f=0;
    min=dx=abs(dx);
    dy=abs(dy);
    if(min>dy)min=dy;
    s+=dx+dy-min*f;
  }
  printf("%d\n",s);
  return 0;
}
