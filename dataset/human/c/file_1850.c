#include <stdio.h>
#include <stdlib.h>
int main(){
  int n;
  int sat;
  int *a,*b,*c;
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  b=(int*)malloc(n*sizeof(int));
  c=(int*)malloc((n-1)*sizeof(int));
  for (int i=0;i<n;i++) scanf("%d",&a[i]);
  for (int i=0;i<n;i++) scanf("%d",&b[i]);
  for (int i=0;i<n-1;i++) scanf("%d",&c[i]);
  sat=0;
  for (int i=0;i<n;i++) sat+=b[a[i]-1];
  for (int i=0;i<n-1;i++){
    if (a[i+1]-a[i]==1) sat+=c[a[i]-1];
  }
  printf("%d\n",sat);
  free(a);
  free(b);
  free(c);
  return 0;
}
