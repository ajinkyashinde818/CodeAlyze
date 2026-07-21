#include <stdio.h>
int main(void){
  int n;  scanf("%d", &n);
  int a[21], b[51], c[51], sumb=0;
  
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);
  for(int i=1; i<=n; i++){
    scanf("%d", &b[i]);
   	sumb += b[i];
  }
  for(int i=1; i<n; i++)
    scanf("%d", &c[i]);
  
  for(int i=1; i<=n-1; i++){
    if(a[i]+1 == a[i+1])
      sumb += c[a[i]];
  }
  
  printf("%d", sumb);
  
  return 0;
}
