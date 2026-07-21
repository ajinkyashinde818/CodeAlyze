#include <stdio.h>

int
main(int argc, char *argv[])
{
  int n, a[100000], ans = - 1;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  int b[100000], i = 0;
  b[0] = 1;
  while(1){
    b[i + 1] = a[b[i] - 1]; 
    if(b[i + 1] == 2){
      ans = i + 1;
      break;
    }
    else if(i == n) break;
    i++;
  }
  
  printf("%d\n", ans);
  
  return 0;
}
