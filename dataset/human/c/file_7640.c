#include <stdio.h>
#include <ctype.h>

#define SIZE 128

int main(void) {
  char integer[SIZE];
  int count = 1;
  int i = 0;

  fgets(integer, SIZE, stdin);
  
  while (integer[0] != '0') {
    printf("Case %d: %s", count, integer);
    
    count++;

    fgets(integer, SIZE, stdin);    
  }
  
  return 0;
}
