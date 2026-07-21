#include <stdio.h>

int
main(int argc, char *argv[])
{
  char s[20];
  int n, k;
  scanf("%d%s%d", &n, s, &k);

  for(int i = 0; i < n; i++){
    if(s[i] != s[k - 1]){
      s[i] = '*';
    }
  }

  printf("%s\n", s);
    

  return 0;
}
