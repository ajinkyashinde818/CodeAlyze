#include<stdio.h>
int main()
{
  char  m[52][53]={""};
  int  h, w, i, j, f = 0;

  scanf("%d %d", &h, &w);
  for( i = 1; i <= h; i++){
    scanf("%s", &m[i][1]);
  }

  for( i = 1; i <= h; i++){
    for( j = 1; j <= w; j++) { 
      if(m[i][j] == '#'){
        if(m[i-1][j] == '#' || m[i+1][j] == '#' || m[i][j-1] == '#' || m[i][j+1] == '#'){
        } else {
          f = 1;
        }
      }
    }
  }

  printf("%s\n", f ? "No" : "Yes");

  return 0;
}
