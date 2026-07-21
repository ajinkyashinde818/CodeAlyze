#include<stdio.h>

int main(){
  int i,j,t,m,a[200000],n=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  t=a[1]-a[0];
  m=a[0];
for(i=0;i<n;i++){
if(m>a[i]){m=a[i];}
if(t<a[i+1]-m && n> i+1){t=a[i+1]-m;}
}

  printf("%d\n",t);
return 0;
}
