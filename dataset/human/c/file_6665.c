#include<stdio.h>
#include<limits.h>

#define max(a,b) a>b?a:b;
#define min(a,b) a<b?a:b;

int main(){
  int i,n,maxv,minv;
  int a[200000];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }

  minv = a[0];
  maxv = INT_MIN;

  for(i=1; i<n; i++){
    maxv = max(maxv,a[i]-minv);
    minv = min(minv,a[i]);
  }
  
  printf("%d\n",maxv);

  return 0;
}
