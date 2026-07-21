#include <stdio.h>
int main(){

  int n,m,zekken[100],blank,i,j;

  scanf("%d %d",&n,&m);

  for(i = 0; i < n; i++){

    scanf("%d",&zekken[i]);

  }

  for(j = 0; j < m; j++){

    for(i = 0; i < n-1; i++){

      if(zekken[i]%(j+1) > zekken[i+1]%(j+1)){

	blank=zekken[i];
        zekken[i]=zekken[i+1];
        zekken[i+1]=blank;

      }

    }

  }

  for(i = 0; i < n; i++){

    printf("%d\n",zekken[i]);

  }

  return 0;

}
