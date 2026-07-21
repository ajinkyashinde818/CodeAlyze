#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ABC179D
//ABC179C
//ABC179B
int main(void) {
  int n, k, i, cou=0, tmp=0;
  scanf("%d", &n);
  int d1[n], d2[n];
  for(i=0; i<n; i++){
    scanf("%d %d", &d1[i], &d2[i]);
    if(d1[i]==d2[i]) cou++;
    else cou=0;
    if(cou==3){
     tmp=1;
    }
  }
  if(tmp==1)printf("Yes");
  else  printf("No");
  return 0;
}
