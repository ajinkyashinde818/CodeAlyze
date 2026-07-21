#include<stdio.h>

int main(void)
{
  int x,y;
  char a[10];
  int i = 0;
  scanf("%d", &x);
  scanf("%s", a);
  scanf("%d", &y);
  
  for (i = 0;i < x; i++){
    if(a[i] != a[y - 1]){
      a[i] = '*';
    }
  }
  printf("%s", a);
  return(0);
}
