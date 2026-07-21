#include <stdio.h>
int main() {
  int h , w , i , j;
  char out;
  while(1) {
    scanf("%d %d",&h,&w);
    if ( h == 0 && w == 0 ) break;
    out = '#';
    for ( i = 0; i < h; i++ ) {
      if ( i % 2 == 0 ) out = '.';
      else out = '#';
      for ( j = 0; j < w; j++ ) {
        if ( out == '#' ) out = '.';
        else out = '#';
        printf("%c",out);
      }
      if ( out == '#' ) out == '.';
      else out = '#';
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
