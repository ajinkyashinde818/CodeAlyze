#include <stdio.h>
#define N 200000

int main(){
  int n, i, j, maxV = 0, minV = 0;
  int a[N];
  scanf("%d", &n);
	
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
	
  minV = a[0];
  maxV = a[1] - a[0];
	
  for(j = 1; j < n; j++){
    if(maxV < (a[j] - minV)) maxV = a[j] - minV;
    if(minV > a[j]) minV = a[j];
  }
	
  printf("%d\n", maxV);
	
return 0; 
}
