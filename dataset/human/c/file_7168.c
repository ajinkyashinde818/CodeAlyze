#include<stdio.h>
#include<string.h>
main() {
  int H,W,g,c,h,w;
  char o[3],p[3];
  strcpy(o,"#.");
  strcpy(p,".#");
  while(1){
    scanf("%d%d",&H,&W);
    if(H==0 && W==0){
      break;
    }
    h=H%2;w=W%2;H=H/2;W=W/2;
    for(c=0;c<H;c++){
      for(g=0;g<W;g++){
	printf("%s",o);
      }
	if(w==1){
	  printf("#");
	}
	printf("\n");
	for(g=0;g<W;g++){
	  printf("%s",p);
	}
	  if(w==1){
	    printf(".");
	  }
	  printf("\n");
    }
    if(h==1){
      for(g=0;g<W;g++){
	printf("%s",o);
      }
      if(w==1){
	printf("#");
      }
      printf("\n");
    }
    printf("\n");
  }
      return 0;
}
