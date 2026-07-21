#include<stdio.h>
int main(){
  int h,w;
  int i,j;
  char a='#',b='.';
  scanf("%d %d",&h,&w);
  while(h!=0||w!=0){
    if(h>=1&&w<=300){
      for(i=0;i<h;i++){
	for(j=0;j<w;j++){
	  if(i%2==0){
	    if(j%2==0){
	      printf("%c",a);
	    }
	    if(j%2==1){
	      printf("%c",b);
	    }
	  }
	  if(i%2==1){
	    if(j%2==0){
	      printf("%c",b);
	    }
	    if(j%2==1){
	      printf("%c",a);
	    }
	  }
	}
	printf("\n");
      }
      printf("\n");
    }
    scanf("%d %d",&h,&w);
  }
  return(0);
}
