#include <stdio.h>

int main(void){

  int n, i, k, p;
  int co[1000];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    
    scanf("%d%d", &k, &p);
    
    if(k < p) co[i] = k;
    else if(k%p != 0) co[i] = k%p;
    else if(k%p == 0) co[i] = p;
  }
  for (i = 0; i < n; i++){
    printf("%d\n", co[i]);
  }
  return 0;
}
