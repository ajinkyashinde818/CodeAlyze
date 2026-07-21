#include <stdio.h>
  
int main()
{
  int i, n, minv, maxv;
  int r;
  
  scanf("%d", &n);
  
  for(i=0; i<n; i++) {
	scanf( "%d", &r );
	if( i == 0 ){
		maxv = -1000-r;
		minv = r;
	}else{
		if(maxv < r-minv) maxv = r-minv;
		if(minv > r) minv = r;
	}
  }
  printf("%d\n", maxv);
  return 0;
}
