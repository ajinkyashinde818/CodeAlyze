#include <stdio.h>

int main(int argc, char *argv[])
{
  int i,j,H,W,count;
  int a[100];
  while(1){
    count=0;
    scanf("%d %d",&H,&W);
    if(H==0 && W==0)return 0;
  
    for (i=0; i<H; i++){
      if(count%2==0){
	for (j=0; j<W; j++)
	  {
	    if(j%2==0)printf ("#");
	    else printf (".");
	  }
      }else{
	for (j=0; j<W; j++)
	  {
	    if(j%2==0)printf (".");
	    else printf ("#");
	  }
      }
      count++;
      printf ("\n"); 
    }
    printf ("\n");
  }
  return 0;
}
