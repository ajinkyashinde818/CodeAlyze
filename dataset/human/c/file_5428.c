#include<stdio.h>

int main(){
  int i;
  int W,H,N,sum=0;
  int x,y,dx,dy,px,py;
  scanf("%d %d %d",&W,&H,&N);
  scanf("%d %d",&x,&y);

  for(i=0;i<N-1;i++){
    scanf("%d %d",&px,&py);
    dx=px-x;
    dy=py-y;
    if(0<=dx&&0<=dy){
      if(dx>dy){
	sum=sum+dx;
      }else{
	sum=sum+dy;
      }
    }else if(dx<=0&&0<=dy){
      dx=-dx;
      sum=sum+dx+dy;
    }else if(dx<=0&&dy<=0){
      dx=-dx;
      dy=-dy;
      if(dx>dy){
	sum=sum+dx;
      }else{
	sum=sum+dy;
      }
    }else if(0<=dx&&dy<=0){
      dy=-dy;
      sum=sum+dx+dy;
    }
    x=px;
    y=py;
  }
  printf("%d\n",sum);
  return 0;
}
