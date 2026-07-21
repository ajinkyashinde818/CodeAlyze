#include <stdio.h>
int main(){

  int n, i;
  int minv, maxv;
  int R[200000];

  scanf("%d",&n);

  for(i=0 ; i<n ; i++){
    scanf("%d",&R[i]);
  }
      
  maxv=R[1]-R[0];
  minv=R[0];
	
  for(i=1 ; i<n ; i++){
    if(R[i]-minv>maxv) maxv=R[i]-minv;
    if(R[i]<minv) minv=R[i];
  }
	 
  printf("%d\n",maxv);
	 
  return 0;
  
}
