#include <stdio.h>

int min(int a, int b, int c){
  if(a > b){
    return (b>c)? c: b;
  }else {
    return (a>c)? c: a;
  }
}

int main(){
  int n;
  while(1){
    scanf("%d", &n);
    if(n==0) break;

    int t[n+1][n+1];

    int i,j;
    int v=0;
    for(i=0;i<=n;i++) for(j=0;j<=n;j++){	
	if(j==0 || i==0) t[i][j] = 0;
	else {
	  char x;
	  scanf(" %c", &x);
	  if(x=='.') {
	    t[i][j] = min(t[i-1][j-1], t[i][j-1], t[i-1][j])+1;
	    v = (v>t[i][j])? v:t[i][j];
	  }
	  else t[i][j] = 0;
	}
      }

    printf("%d\n", v);
  }
}
