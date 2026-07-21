#include<stdio.h>

int main()
{
  char  a[50][51], b[50][51];
  int  n, m, i, j, k, l, f=0;

  scanf("%d %d", &n, &m);
  
  for(i=0; i < n; i++){
     scanf("%s", a[i]);
  }
  for(k=0; k < m; k++){
     scanf("%s", b[k]);
  }

  for(i=0; i <= n-m; i++){
    for(j=0; j <= n-m; j++){
      f = 0;
      for(k=0; k < m; k++){
        for(l=0; l < m; l++){
          if(a[i+k][j+l] == b[k][l]){
            f++;
          }
        }
      }
      if( f == m*m ){
        break;
      }
    }
    if( f == m*m ){
      break;
    }
  }

  if( f == m*m){
    printf("Yes\n");
  }else {
    printf("No\n");
  }

  return 0;
}
