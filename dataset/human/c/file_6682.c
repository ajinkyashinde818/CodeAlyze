#include <stdio.h>
#define BUF_SIZE 100
#define LONG_MIN -2147483646
#define LONG_MAX 2147483647

int main(void)
{
  char buf[100];
  long input, maxv = LONG_MIN, min = LONG_MAX;
  long linum;
  long diff = 0;

  fgets(buf, BUF_SIZE, stdin);
  sscanf(buf, "%ld", &linum);

  while(linum--){
    fgets(buf, BUF_SIZE, stdin);
    if(buf[0] == '\n') break;
    sscanf(buf, "%ld", &input);

    diff = input - min;
    if(maxv < diff){
      maxv = diff;
    }

    if(input < min){
      min = input;
    }

  }

  printf("%ld\n", maxv);

  return 0;
}
