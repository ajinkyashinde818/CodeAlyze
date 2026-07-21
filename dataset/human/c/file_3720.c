#include <stdio.h>
#include <string.h>

int main(void)
{
  char buff[100];
  fgets(buff, sizeof buff, stdin);

  long a, b;
  a = atol(strtok(buff, " "));
  b = atol(strtok(NULL, " "));
  
  long ax =1, bx = 1;
  while (a * ax != b * bx) {
    if (a * ax < b * bx) {
      ax++;
    } else {
      bx++;
  	}
  }
  printf("%ld", a * ax);
  return 0;
}
