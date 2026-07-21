#include<stdio.h>

int main(){
  int i, j, maxv=-1000000000, minv, n, r;

  scanf("%d", &n);
  
  for(i=0; i<n; i++){
    scanf("%d", &r);
    if(i==0){
      minv=r;
    }else{      
      if(maxv<r-minv){
	maxv=r-minv;
      }
      if(minv>r){
	minv=r; 
      }
    }    
  }

  printf("%d\n", maxv);
  
  return 0;
}
