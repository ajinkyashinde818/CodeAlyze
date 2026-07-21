#include<stdio.h>

int main(void){
  int i,j,k,l;
  int h,w;
  char map[1000][1000];
  int n;
  int max,min;

  while(1){
    scanf(" %d ",&n);
    if(!n)break;
    
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	scanf(" %c ",&map[i][j]);
      }
    }
    
    max = 0;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	h = 0;
	w = 0;
	while(map[i+h][j] == '.' && i+h < n)h++;
	while(map[i][j+w] == '.' && j+w < n)w++;
	if(h<w)min = h;
	else min = w;
	for(k=1;k<min;k++){
	  for(l=1;l<min;l++){
	    if(map[i+k][j+l] == '*'){
	      min = l;
	      break;
	    }
	  }
	}
	if(min>max)max = min;
      }
    }
    
    printf("%d\n",max);
    
  }

  return 0;
}
