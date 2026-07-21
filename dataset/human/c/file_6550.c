#include<stdio.h>
#include<math.h> // add option -lm
int main() {
  
  int minv,maxv,n;
  int i, j ;
  
  scanf("%d",&n);
  
  int r[n];
  for(i = 0 ; i < n ; i++) {
    scanf("%d",&r[i]);
  }
  minv = r[0];
  maxv = r[1]-r[0] ;
  
  for(j = 1; j < n ; j++) {
    maxv = fmax(maxv, r[j]-minv);    
    minv = fmin(minv, r[j]);
   
  }
  printf("%d\n",maxv);
  return 0;
}
