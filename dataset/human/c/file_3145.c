#include <stdio.h>
int main(void){
  int n, s;
  scanf("%d", &n); scanf("%d", &s);
  int i;
  int a[s];
  int b[s];
  int c=0;
  for (i=0; i<s;i++){
    scanf("%d", &a[i]);
  }
  b[s-1]=n-a[s-1]+a[0];
  c=b[s-1];
  for (i=0; i<s-1; i++){
    b[i]=a[i+1]-a[i];
    if (c<b[i]){
      c=b[i];
    }
  }
  printf("%d", n-c);
  
  return 0;
}
