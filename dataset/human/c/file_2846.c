#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){

  int k,s;
  int i,j,p;
  int cnt = 0;

  scanf("%d %d", &k, &s);

  for(i = 0;i <= k;i++){
    for(j = 0;j <= k;j++){
        if(0 <= s - (i + j) && s - (i + j) <= k) cnt++;
    }
  }

  printf("%d\n", cnt);

  return 0;
}
