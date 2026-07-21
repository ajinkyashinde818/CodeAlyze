#include<stdio.h>

int main(void)
{
  while(1){
    int h,w;
    int i,j;

    scanf("%d %d",&h,&w);
    if( h==0 && w==0 )break;

    for( i=0; i<h; i++ ){
      if( i%2==0 ){
	for( j=0; j<w; j++ )
	  if( j%2==0 )putchar('#');
	  else putchar('.');
      }
      else {
	for( j=0; j<w; j++ )
	  if( j%2==0 )putchar('.');
	  else putchar('#');
      }
      puts("");
    }
    printf("\n");
  }
  return 0;
}
