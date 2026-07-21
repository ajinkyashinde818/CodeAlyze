#include<stdio.h>
int main(){
  int h[256],w[256],i=0,j,c=0,k;
  while(1){
    scanf("%d %d",&h[i],&w[i]);
    if(h[i]==0&&w[i]==0){
      break;
    }
    i++;
    c++;
  }
  for(k=0;k<c;k++){
    for(i=1;i<=h[k];i++){
      for(j=1;j<=w[k];j++){
	if(i%2==1){
	  if(j%2==1){
	    printf("#");
	  }else{
	    printf(".");
	  }
	}else{
	  if(j%2==1){
	    printf(".");
	  }else{
	    printf("#");
	  }
	}
      }
      printf("\n");
    }
    printf("\n");
  }
  return(0);
}
