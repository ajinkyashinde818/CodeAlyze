#include<stdio.h>
 
int main(void){
  int n, d, x;
  int a;
  int i, j;
  scanf("%d %d %d", &n, &d, &x);
  int sum=x;
  for(i=0;i<n;i++){
    scanf("%d", &a);
    for(j=1;j<=d;j+=a){
      sum++;
    }
  }
  printf("%d", sum);
  return 0;
}
