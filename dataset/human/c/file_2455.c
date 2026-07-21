#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(void){
  int a = FALSE;
  int b = FALSE;
  int c = FALSE;
  char s;
  int i;
  
  for( i=0; i<3; i++){
    scanf("%c",&s);
    if( s == 'a' ) a = TRUE;
    if( s == 'b' ) b = TRUE;
    if( s == 'c' ) c = TRUE;
  }
  
  ( a == TRUE && b == TRUE && c == TRUE ) ? printf("Yes\n") : printf("No\n");
  
  return 0;
}
