#include <stdio.h>

int main() {
  int H[30],W[30],i,j,n,m;
  for(n=0;;n++) {
    scanf("%d %d",&H[n],&W[n]);
    if (H[n] == 0 && W[n] == 0) break;
  }
  for(m=0;m<n;m++) {
    for (i=0;i<H[m];i++) {
      if (i%2==0) {
	for(j=0;j<W[m];j++) {
	  if (j%2==0){
	    printf("#");
	  } else {
	    printf(".");
	  }
	}
      } else {
	for(j=0;j<W[m];j++) {
	  if (j%2==0){
	    printf(".");
	  } else {
	    printf("#");
	  }
	}
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
