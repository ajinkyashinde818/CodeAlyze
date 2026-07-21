#include<stdio.h>
#include<string.h>

int main(void){
  int a, b;
  int i;
  char str[10];
  char ch;
  scanf("%d", &a);
  scanf("%s", str);
  scanf("%d", &b);
  ch = str[b-1];
  for ( i = 0; i < a; i++ ) {
    if ( str[i] != ch ) {
      str[i] = '*';
    }
  }
  printf("%s", str);
  return 0;
}
