#include<stdio.h>
#define N 200000

int main(){
  int n,a[N],i,j,minv,maxv=0;
  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%d",&a[i]);
  }
  minv = a[0];
  for(j=1 ; j<n ; j++){
    if(maxv<a[j]-minv || j==1) maxv=a[j]-minv;
    if(minv>a[j])minv = a[j];
  }
  printf("%d\n",maxv);
  return 0;
}
