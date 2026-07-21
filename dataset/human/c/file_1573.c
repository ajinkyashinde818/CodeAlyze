#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
  int x, y;
  scanf("%x %x", &x, &y);
  if(x<y)printf("<\n");
  if(x>y)printf(">\n");
  if(x==y)printf("=\n");
  return 0;
}
