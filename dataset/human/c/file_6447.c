#include <stdio.h>

int main(){

  int max,first,tmp,num,i;

  scanf("%d",&num);
  scanf("%d",&first);
  scanf("%d",&tmp);
  max = tmp - first;
  if(tmp<first){
    first = tmp;
  }

  for(i=2;i<num;i++){
    scanf("%d",&tmp);
    if(max<tmp-first) max=tmp-first;
    if(tmp<first){
      first=tmp;
    }
  }
  printf("%d\n",max);
  
  return 0;
}
