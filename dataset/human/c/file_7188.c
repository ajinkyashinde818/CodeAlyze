#include <stdio.h>

int main(void)
{

  int h,w;

  for(;;){
    scanf("%d %d",&h,&w);
    if(h==0&&w==0)break;
    int i,j;

    for(j=1;j<=h;j++){
      if(j%2){
	for(i=1;i<=w;i++){
	  if(i%2)printf("#");
	  else printf(".");
	}
      }
      else{
	for(i=1;i<=w;i++){
	  if(i%2)printf(".");
	  else printf("#");
	}
      }
      putchar('\n');
    }
    putchar('\n');
  }
  return 0;
}
