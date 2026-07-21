#include <stdio.h>
#include <string.h>

int main(){
  char	x[2]={0};
  char	y[2]={0};
  scanf("%s %s", x, y);
  
  if	 ( strcmp(x,y)==0 ){ printf("="); }
  else if( strcmp(x,y) >0 ){ printf(">"); }
  else					   { printf("<"); }

  return 0;
}
