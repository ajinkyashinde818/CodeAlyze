#include <stdio.h>

int
main(int argc, char *argv[])
{
  char a[50][51], b[50][51];
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%s", a[i]);
  for(int j = 0; j < m; j++) scanf("%s", b[j]);

  int l = n - m; int cnt; char flag = 0;
  for(int i = 0; i <= l; i++){
    for(int j = 0; j <= l; j++){
      cnt = 0;
      for(int x = 0; x < m; x++){
	for(int y = 0; y < m; y++){
	  if(b[x][y] == a[i + x][j + y]) cnt++;
	}
      }
      if(cnt == m * m){
	flag = 1;
	break;
      }
    }
    if(flag == 1) break;
  }

  if(flag == 0) printf("No\n");
  else printf("Yes\n");

  return 0;
}
