#include <stdio.h>
#include <string.h>

int main(void) {

  int n;

  char img[1000][1000];

  char buf[1100];

  int max,length;
  int flag;

  int i,j,k,l,x;


  while(1) {

    scanf("%d",&n);

    if(n==0) break;

    getchar();

    for(i=0;i<n;i++) {

      fgets(buf,sizeof(buf),stdin);

      buf[strlen(buf)-1]='\0';

      for(j=0;j<n;j++) {

	img[i][j]=buf[j];

      }

    }

    max=0;

    for(i=0;i<n;i++) {

      for(j=0;j<n;j++) {

	length=0;

	for(x=0;x<n;x++) {

	  flag=1;

	  for(k=0;k<=x;k++) {

	    for(l=0;l<=x;l++) {

	      if(i+k>=n || j+l>=n) goto Compare;

	      if(img[i+k][j+l]=='*') {

		flag=0;
		goto Compare;

	      }

	    }

	  }

	  length++;
	  //printf("%d ",length);

	}

      Compare:

	if(max<length) max=length;

      }

    }


    /*for(i=0;i<n;i++) {

      for(j=0;j<n;j++) {

	printf("%c",img[i][j]);

      }

      puts("");

      }*/

    printf("%d\n",max);

  }

  return 0;

}
