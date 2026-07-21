#include <stdio.h>

int main() {
  int data[501][501];
  int n,m;
  int a,b;
  int i,j,count;
  int f[501];
  
  while(1){
    count = 0;
    for(i = 0; i < 501; i++){
      for(j = 0; j < 501; j++){
	data[i][j] = 0;
	f[j]=0;
      }
    }
    scanf("%d %d",&n,&m);
    if(n == 0 && m == 0)
      break;
    for( i = 0; i < m; i++){
      scanf("%d %d",&a,&b);
      data[a][b] = 1;
      data[b][a] = 1;
    }
    
    for(i = 1; i <= n; i++){
      if(data[1][i] == 1){
	f[i]=1;
	for(j = 2; j <= n; j++){
	  if(data[i][j] == 1 && data[1][j] != 1)
	    f[j]=1;
	}
      }
    }

    /*for(i = 1; i <= n; i++) {
      f[i] += data[1][i];
      if(f[i] >= 1) {
	for(j = 2; j <= n; j++) {
	  f[j] += data[i][j];
	}
      }
      }*/

    for(i=2;i<=n;i++){
	count += f[i];
    }
    printf("%d\n",count);
  }
  return 0;
}
