#include <stdio.h>

int a[8][8] = { {1, 2, 1, 2, 1, 4, 1, 4},
		{1, 2, 1, 4, 1, 4, 1, 2},
		{1, 4, 1, 2, 1, 2, 1, 4},
		{1, 4, 1, 4, 1, 2, 1, 2},
		{2, 1, 2, 1, 4, 1, 4, 1},
		{2, 1, 4, 1, 4, 1, 2 ,1},
		{4, 1, 2, 1, 2, 1, 4, 1},
		{4, 1, 4, 1, 2, 1, 2, 1} };
int main(){
  int p[8], c[8], v,i , j, f, s, res, odd;

  while(scanf("%d%d%d%d%d%d%d%d", &p[0], &p[1], &p[2], &p[3], &p[4], &p[5], &p[6], &p[7]) != EOF){
    s = 9999999;
    for(i = 0; i < 8; ++i){
      odd = 0;
      for(j = 0; j < 8; ++j) odd += a[i][j] < p[j] ? p[j] - a[i][j] : 0;
      if(s > odd){ s = odd; res = i;}
    }

    for(i = 0; i < 8; ++i) printf(i ? " %d" : "%d", a[res][i]);
    puts("");
  }
  return 0;
}
