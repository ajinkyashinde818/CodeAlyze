#include <stdio.h>
int main(void)
{
  int k, s, i, j, z, cou=0;
  scanf("%d %d", &k, &s);

  for(i = 0; i <= k; i++){
    for(j = 0; j <= k; j++){
      z = s-i-j;
      if(0 <= z && z <= k){
	if(i+j+(s-i-j) == s) cou++;
      }
    }
  }
  printf("%d\n", cou);
  return 0;
}
