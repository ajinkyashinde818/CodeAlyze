#include <stdio.h>
#define N 200000

int main(){
  int n, num[N]={0};
  int i = 0, j, max, minnum;
  
  scanf("%d", &n);
  
  while(i<n){
    scanf("%d", &num[i]);
    i++;
  }
  
  max = num[1] - num[0];
  minnum= num[0];
    
  for(i = 0; i < n; i++){
    if(minnum < num[i]){
      continue;
    }

    minnum = num[i];
    
    for(j = i+1; j < n; j++){
      if(max < num[j] - minnum){
	max = num[j] - minnum;
      }
    }  
  }
  
  /*  
  max = num[1];
  min = num[0];
  for(i = 1; i < n; i++){
    if(max <= num[i]){
      max = num[i];
      
      for(j = 0; j < i; j++){
	if(min > num[j]){
	  min = num[j];
	}
	
      }
    }
  }
  */
  
  printf("%d\n", max);
  
  return 0;
}
