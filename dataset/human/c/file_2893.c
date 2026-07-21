#include<stdio.h>

int main(){
  int x,y,z,s,k,cnt=0;
  scanf("%d %d",&k,&s);
  for(int i=0;i<=k;i++){
    if(s-i<=2*k)
      for(int j=0;j<=k;j++)
        if(s-(i+j)<=k&&s-(i+j)>=0)
          cnt++;
  }
  printf("%d\n",cnt);
}
