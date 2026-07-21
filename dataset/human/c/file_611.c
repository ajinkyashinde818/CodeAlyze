#include<stdio.h>

int main(void) {

  char A[60][60];
  char B[60][60];
  int N,M;
  int i,j;

  scanf("%d %d",&N,&M);
  for(i=0;i<N;i++){
    scanf("%s",A[i]);
  }
  for(i=0;i<M;i++){
    scanf("%s",B[i]);
  }

  int count;
  int max;
  int num;
  int x,y;
  int flag;
  int yes = 0;
  max = M * M;
  num = N - M + 1;
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      count = 0;
      flag = 1;
      for(x=0;x<M;x++){
	for(y=0;y<M;y++){
	  if(A[i+x][j+y] == B[x][y]){
	    count++;
	  } else { 
	    flag =0;
	  }
	  if(flag==0){
	    break;
	  }
	}
	if(flag==0){
	  break;
	}
      }
      if(count==max){
	yes = 1;
      }
      if(yes){
	break;
      }
    }
    if(yes){
      break;
    }
  }

  if(yes){
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
