#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 10

int main(void) {
  FILE *fp = stdin;
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, fp)) return 0;
  int num;
  sscanf(line, "%d", &num);
  int *arr = malloc(sizeof(int)*(num+1));

  int i;
  for(i = 1; i <= num; i++) {
    if(!fgets(line, BUF_SIZE, fp)) return 0;
    sscanf(line, "%d", &arr[i]);
  }

  int light = 1;
  char checked[100001] = {0};
  int cnt = 0;
  while(1) {
    light = arr[light];
    cnt++;
    if(checked[light]) break;
    checked[light] = 1;
    if(light == 2) {
      printf("%d\n", cnt);
      return 0;
    }
  }
  printf("-1\n");

  return 0;
}
