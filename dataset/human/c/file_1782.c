#include <stdio.h>
int main(){
  int n, a[21]={0}, b[21]={0}, c[21]={0}, cnt=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++){ scanf("%d",&a[i]); }
  for(int i=0; i<n; i++){ scanf("%d",&b[i]); }
  for(int i=0; i<n; i++){ scanf("%d",&c[i]); }
  for(int i=0; i<n; i++){
    cnt += b[a[i]-1];
    if( i!=0 && a[i-1]==a[i]-1 ){ cnt += c[a[i]-1-1]; }
  }
  printf("%d",cnt);
  return 0;
}
