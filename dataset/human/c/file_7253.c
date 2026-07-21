#include<stdio.h>

int main(){
  int a,b,i,j;
  while(1){

    scanf("%d%d",&b,&a);
    if(a==0&&b==0)break;

    for(i=0;i<b;i++){
      for(j=0;j<a;j++){
	if(((i+j)%2)==0){
	  printf("#");
	}
	else{
	  printf(".");
	}
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
