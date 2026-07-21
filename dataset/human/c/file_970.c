#include <stdio.h>
int main(void){
  int e,y;
  scanf("%d %d",&e,&y);
  if(e==0){
      if(1868<=y&&y<=1911) printf("M%d\n",y-1868+1);
      else if(1912<=y&&y<=1925) printf("T%d\n",y-1912+1);
      else if(1926<=y&&y<=1988) printf("S%d\n",y-1926+1);
      else printf("H%d\n",y-1989+1);
  }
  else if(e==1) printf("%d\n",1867+y);
  else if(e==2) printf("%d\n",1911+y);
  else if(e==3) printf("%d\n",1925+y);
  else printf("%d\n",1988+y);
   return 0;
}
