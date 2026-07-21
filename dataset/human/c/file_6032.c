#include<stdio.h>

int main() {
  int m,n,nn,i,a[200000];

  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  m=a[1]-a[0];
  nn=a[0];

  for(i=1;i<n;i++) {
    if(m <a[i]-nn) 
      m=a[i]-nn;

    if(nn>a[i]) nn=a[i];
  }
  printf("%d\n",m);
  return 0;
}
