#include<stdio.h>
int main(){
  int m,n,i,r;
  int a[2000000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  m=a[0];
  r=a[1]-m; 
  if(r<0) m=a[1];
  
  for(i=2;i<n;i++){
    if(a[i]-m>r) r=a[i]-m;
    if(m>a[i]) m=a[i];
  }

  printf("%d\n",r);
  return 0;
}
