#include <stdio.h>

int main(){
  int n;
  int a[200000];
  int max,i,j,min;
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  max=a[1]-a[0];
  min=a[0];
  for(i=1; i<n; i++){
    if(min>a[i]) min=a[i];
    else{
      a[i]-=min;
      if(a[i]>max) max=a[i];
    }
  }
  printf("%d\n",max);
  return 0;
}
