#include<stdio.h>

int main(){
  int k,s,x,y,cnt=0;
  scanf("%d%d",&k,&s);
  for(x=k;x>=0;x--){
    if(s-x>2*k) break;
    else{
      for(y=k;y>=0;y--){
        if(s-x-y<=k&&s-x-y>=0) {
        cnt++;
//        printf("%d %d %d\n",x,y,s-x-y);
        }
      }
    }
  }
  printf("%d\n",cnt );
  return 0;
}
