#include<stdio.h>

int main(){
  int i,line,num,cnt=0;
  scanf("%d %d",&num,&line);
  int height[num];
  for(i=0;i<num;i++){
    scanf("%d",&height[i]);
    if(height[i]>=line) cnt++;
  }
  
  printf("%d",cnt);
  return 0;
}
