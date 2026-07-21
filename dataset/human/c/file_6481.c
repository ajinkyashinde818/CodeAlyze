#include  <stdio.h>

int main() {
  int n,i,max,min;
  int MAX=200000;
  int R[MAX];
  i=0;
  while(1){
    scanf("%d",&n);
    if(2<=n&&n<=MAX){
      while(1){
	if(n==i) break;
	scanf("%d", &R[i]);
	if(1<=R[i]&&R[i]<=1000000000) i++;
      }
      break;
    }
  }

  max=-2000000000;
  min=R[0];
  
  for(i=1;i<n;i++){
    if(max<R[i]-min) max=R[i]-min;
    if(min>R[i]) min=R[i];
  }
    
  printf("%d\n",max);
   
  return 0;
}
