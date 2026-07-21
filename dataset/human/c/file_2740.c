#include <stdio.h>
int main(){
 int k,s,p=0;
  scanf("%d %d",&k,&s);
  for(int x=k;x>=0;x--){
    for(int y=k;y>=0;y--){
      if(s-x-y<=k&&s-x-y>=0) p++;
    }
  }
  printf("%d\n",p);
  return 0;
}
