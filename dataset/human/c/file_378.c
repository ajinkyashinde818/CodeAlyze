#include <stdio.h>

int main (){
  int n, r, valor, classificacao;
  scanf("%d%d", &n, &r);

  if(n<10){
    valor= 100*(10-n);
    valor+r;
    printf("%d\n", valor+r);
  }
  else{
    printf("%d\n", r);
  }
  
return 0;
}
