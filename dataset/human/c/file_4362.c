#include<stdio.h>

int main(void){
	int N;
	scanf("%d",&N);
	int D[N][2];
	int ans=0;

	for(int i=0;i<N;i++){
      scanf("%d %d",&D[i][0],&D[i][1]);
	  if(D[i][0]==D[i][1]) ans+=1;
	  else ans=0;

	  if (ans==3) {
		  printf("Yes\n");
		  return 0;
	  }
	}

 printf("No\n");
	return 0;
}
