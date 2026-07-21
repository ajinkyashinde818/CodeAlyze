#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
  int n,k,x;
  int i;
  int a = 0;

  scanf("%d %d", &n, &k);

  for(i = 0;i < n;i++){
    scanf("%d", &x);
    if(x >= k) a++;
  }

  printf("%d\n", a);

  return 0;
}
