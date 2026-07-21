#include <stdio.h>
#include <math.h>

int main(void){
  int i, j, k = 3, a, n, s[10000], p[10000];

  p[0] = 1;  s[0] = 0;
  p[1] = 2;  s[1] = 2;
  p[2] = 3;  s[2] = 5;
  for(i = 5; i <= 104729; i += 2){
    a = 0;
    for(j = 2; p[j] <= sqrt((double)i); j++){
      if(i % p[j] == 0){
	a++;
	break;
      }
    }
    if(a == 0){
      p[k] = i;
      s[k] = s[k-1]+p[k];
      k++;
    }
  }

  scanf("%d", &n);
  while(n != 0){
    printf("%d\n", s[n]);
    scanf("%d", &n);
  }
  return 0;
}
