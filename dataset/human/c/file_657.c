#include<stdio.h>
#include<stdbool.h>

int main(void) {
  int N, M;
  scanf("%d %d", &N, &M);
  char A[50][51];
  for(int i = 0; i < N; i++) {
    scanf("%s", A[i]);
  }
  char B[50][51];
  for(int i = 0; i < M; i++) {
    scanf("%s", B[i]);
  }

  for(int y = 0; y <= (N-M); y++) {
    for(int x = 0; x <= (N-M); x++) {

      bool find = true;
      for(int i = 0; i < M; i++) {
	for(int j = 0; j < M; j++) {
	  if(B[i][j] != A[y+i][x+j]) {
	    find = false;
	    break;
	  }
	}
	if(find == false)
	  break;
      }
      if(find == true) {
	printf("Yes\n");
	return 0;
      }

    }
  }

  printf("No\n");
  return 0;
}
