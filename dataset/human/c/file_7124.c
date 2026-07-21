#include<stdio.h>

int main(){
  int w,h;
  int i,j;
  while(scanf("%d%d",&w,&h), w!=0&&h!=0){
    for(i=0; i<w; i++){
     for(j=0; j<h; j++){
	 if(i%2==0&&j%2==0||i%2!=0&&j%2!=0)putchar('#');
	 else putchar('.');
      }
      putchar('\n');
    }
    putchar('\n');
  }

  return 0;
}
