#include <stdio.h>

int main(void){
	int n;
	scanf("%d", &n );
	int a[n], b[n], c[n-1];
  int ans=0;
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	  for(int i=0;i<n;i++){
		scanf("%d", &b[i]);
      	ans += b[i];
	}
  for(int i=0;i<n-1;i++){
		scanf("%d", &c[i]);
	}

	for(int i=1;i<n;i++){
      if(a[i]-a[i-1]==1)	ans+=c[a[i-1]-1];
    }
	printf("%d", ans);

	return 0;
	
}
