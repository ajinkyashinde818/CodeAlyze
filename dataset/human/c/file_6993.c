#include <stdio.h>

main(){
  int H, W, r, s;

  while(1){
    if(H==0 && W==0) break;
    scanf("%d %d", &H, &W);

    for(r=0;r<H;r++){
      for(s=0;s<W;s++){
	if((r+s)%2==0) printf("#");
	else printf(".");
      }
      printf("\n");
    }
    if(H!=0 || W!=0) printf("\n");
  }
  return 0;
}
