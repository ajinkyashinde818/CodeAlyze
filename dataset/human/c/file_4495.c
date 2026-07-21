#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
  int n;
  scanf("%d", &n);
  int a[n], b[n], i;
  for(i = 0; i < n; i++){
    scanf("%d%d", &a[i], &b[i]);
  }
  int zorome = 0, frag = 0;
  for(i = 0; i < n; i++){
    if(a[i] == b[i]){
      zorome = zorome + 1;
    }else{
      zorome = 0;
    }
    if(zorome == 3){
      printf("Yes\n");
      frag = 1;
      break;
    }
  }

  if(frag == 0){
    printf("No\n");
  }
  return 0;
}
