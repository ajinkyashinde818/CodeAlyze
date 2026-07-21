#include <stdio.h>
#include <string.h>
char l[501];
char h[501][501];
int main()
{
  int n,m,i,j,k;
  for(;;){
    scanf("%d",&n);
    scanf("%d",&m);
    if(n == 0 && m == 0) break;
    memset(l,0,sizeof(l));
    memset(h,0,sizeof(h));
    for(i=0;i<m;i++){
      scanf("%d%d",&j,&k);
      h[j][k] = 1;
      h[k][j] = 1;
    }
    for(i=2;i<=n;i++){
      if(h[1][i] == 1){
	l[i] = 1;
	for(j=1;j<=n;j++){
	  if(h[i][j] == 1) l[j] = 1;
	}
      }
    }
    j = 0;
    for(i=2;i<=n;i++){
      if(l[i] == 1) j++;
    }
    printf("%d\n",j);
  }
  return 0;
}
