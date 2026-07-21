#include <stdio.h>

#define DIRT '*'
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main(){
  int n, i, j, map[1002][1002], max;
  char s[1001];

  while(scanf("%d", &n) && n){
    for(i = 0; i < n; ++i){
      scanf("%s", s);
      for(j = 0; j < n; ++j) map[i][j] = s[j] == DIRT ? 0 : 1;
    }

    /*    for(i = 0; i < n; ++i){
      for(j = 0; j < n; ++j) printf( j ? " %d" : "%d", map[i][j]);
      puts(""); 
      } */
    for(i = 1; i < n; ++i)
      for(j = 1; j < n; ++j)
	if(map[i][j] != 0)
	  map[i][j] = MIN(map[i - 1][j - 1], MIN(map[i - 1][j], map[i][j - 1])) + 1;
    max = 0;
    for(i = 0; i < n; ++i)
      for(j = 0; j < n; ++j)
	max = max < map[i][j] ? map[i][j] : max;

    printf("%d\n", max);
  }
  return 0;
}
