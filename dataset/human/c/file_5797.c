#include <stdio.h>

int main(){
  int i, j, n;
  int a[200000];
  int min,ans;

  scanf("%d",&n);
  
  for(i=0; i<n; i++)
    scanf("%d",&a[i]);

  min=a[0];
  ans=a[1]-a[0];

  for(i=1; i<n; i++){
    if(ans<a[i]-min)
      ans=a[i]-min;
    if(a[i]<min)
      min=a[i];
  }
    
  
  printf("%d\n",ans);

  return 0;
}
