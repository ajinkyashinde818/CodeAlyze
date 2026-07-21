#include <stdio.h>

char n[51][51], m[51][51];
int N, M;

int serch(int x, int y);

int main(void)
{
  int i, j;

  scanf("%d %d", &N, &M);

    for(i = 0; i <  N; i++)
    scanf("%s", n[i]);
  

    for(i = 0; i < M; i++)
    scanf("%s", m[i]);

  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      if(m[0][0] == n[i][j]){
      int se = serch(i, j);
      if(se){
	printf("Yes\n");
	return 0;
      }
      }
    }
  }
  printf("No\n");
  return 0;
}

  int serch(int x, int y){
    int i, j;
      for(i = 0; i <  M; i++){
	for(j = 0; j <  M; j++){
	  if(x+i < N && y+j < N){
	  if(n[x+i][y+j] != m[i][j])
	    return 0;
	     }else{
	      return 0;
	    }
	}
      }
      return 1;
  }
