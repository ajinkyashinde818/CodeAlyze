#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))
//　35min
int main(void){
  int n, m;
  char a[51][51];
  char b[51][51];
  int check = 1;

  scanf("%d%d", &n, &m);
  
  for(int i = 0; i < n; i++){
    scanf("%s", a[i]);
  }

  for(int i = 0; i < m; i++){
    scanf("%s", b[i]);
  }

  //縦軸にずらす
  for(int i = 0; i < n - m + 1; i++){
    //横軸にずらす
    for(int j = 0; j < n - m + 1; j++){
      for(int k = 0; k < m; k++){
	for(int l = 0; l < m; l++){
	  if(a[i + k][j + l] == b[k][l]){
	    if(check == 1 && k == m - 1 && l == m - 1){
	      printf("Yes\n");
	      return 0;
	    }
	  }else{
	    check = 0;
	    break;
	  }

	}
      }
      check = 1;
    }
  }

  printf("No\n");

  return 0;
}
