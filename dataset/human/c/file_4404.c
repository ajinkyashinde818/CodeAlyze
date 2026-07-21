#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(void){
  int N,i;
  int count=0,yes=0;
  int D[101][2];

  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d %d", &D[i][0],&D[i][1]);

    if(D[i][0]==D[i][1]){
      count++;
      if(count==3) yes++;
    }
    else count=0;

  }

  if(yes>=1) printf("Yes\n");
  else printf("No\n");

  return 0;

}
