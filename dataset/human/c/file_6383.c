#include <stdio.h>

int main(){
  int n,i;
  int maxv;
  int minv;
  scanf("%d",&n);
  int r[n];
  for(i = 0; i < n; i++){
    scanf("%d",&r[i]);
  }
  maxv = r[1] - r[0];
  minv = r[0];
  for(i = 1; i < n; i++){
    if(maxv < r[i] - minv){
      maxv = r[i] - minv;
    }
    if(minv > r[i]){
      minv = r[i];
    }
  }
  printf("%d\n",maxv);
  return 0;
}
