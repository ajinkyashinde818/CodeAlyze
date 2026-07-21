#include<stdio.h>
int main(){
  int h[300],w[300],i,j,k,n=0;
  char a,b;
  a='#';
  b='.';
  while(1){
  scanf("%d %d",&h[n],&w[n]);
  if(h[n]==0&&w[n]==0)break;
  n++;
  }
  for(k=0;k<n;k++){
    for(i=0;i<h[k];i++){
      if(i%2==0){
	for(j=0;j<w[k];j++){
	  if(j%2==0){
	    printf("%c",a);
	  }else{
	    printf("%c",b);
	  }
	}
	printf("\n");
      }else{
	for(j=0;j<w[k];j++){
	  if(j%2==0){
	    printf("%c",b);
	  }else{
	    printf("%c",a);
	  }
	}
	printf("\n");
      }
    }
      printf("\n");
  }
  return(0);
}
