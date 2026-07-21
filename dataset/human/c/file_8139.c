#include <stdio.h>

int main(void){
  int a,b,c,d;
  int res_f,res_s;
  
  scanf("%d%d%d%d",&a,&b,&c,&d);

  res_f = a*b;
  res_s = c*d;
  
  if(res_f >= res_s){
    printf("%d\n",res_f);
  }
  else{
    printf("%d\n",res_s);
  }
  return 0;
}
