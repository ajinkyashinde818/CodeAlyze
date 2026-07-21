#include <stdio.h>
int main(){
  int a,b[100]={},c[100]={},count_same=0,flag=0;
  scanf("%d",&a);
  for(int i=0;i<a;i++){
      scanf("%d%d",&b[i],&c[i]);
    if(b[i]==c[i]) count_same++;
    else count_same=0;
    if(count_same==3){
      flag++;
      break;
    }
  }
  
  if(flag)printf("Yes");
  else printf("No");
  return 0;
}
