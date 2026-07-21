#include <stdio.h>
int main(){
  int pep,lim,i;
  int count = 0;
  int hei[100010];
  scanf("%d%d",&pep,&lim);
  for(i=0;i<=pep;i++){scanf("%d",&hei[i]);}  
  for(i=0;i<pep;i++){
    if(hei[i] >= lim)count++;
  }
  printf("%d",count);
}
