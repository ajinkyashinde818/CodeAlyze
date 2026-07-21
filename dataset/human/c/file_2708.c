#include <stdio.h>

int main(void){
  int K,S;
  int x,y,z;
  int count;

  scanf("%d%d",&K,&S);

  for(x=0;x<=K;x++){
    for(y=0;y<=K;y++){
      z=S-x-y;
      if(z>=0 && z<=K)
	count+=1;
    }
  }

  printf("%d\n",count);

  return 0;
}
