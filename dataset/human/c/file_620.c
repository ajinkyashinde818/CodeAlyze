#include <stdio.h>

int main(void)
{
  int N, M;
  char A[50][50];
  char B[50][50];
  int i, j;
  int s, t;
  int f = 0;
  int tmp = 1;

  scanf("%d %d", &N, &M);
  for(i = 0; i < N; i++) {
    scanf("%s", &A[i]);
  }
  for(i = 0; i < M; i++) {
    scanf("%s", &B[i]);
  }

  for(i = 0; i < N-M+1; i++) {
    for(j = 0; j < N-M+1; j++) {
      if(A[i][j] == B[0][0]) {
	for(s = 0; s < M; s++) {
	  for(t = 0; t < M; t++) {
	    if(A[i+s][j+t] != B[s][t]) {
	      tmp = 0;
	      break;
	    }
	  }
	  if(tmp == 0) {
	    tmp = 1;
	    break;
	  }
	}
	if(s == M && t == M) {
	  f = 1;
	  break;
	}
      }
      if(f == 1) {
	break;
      }
    }
    if(f == 1) {
      break;
    }
  }

  if(f == 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
