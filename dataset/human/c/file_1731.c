#include<stdio.h>
int main(void){
  int n;
  scanf("%d",&n);
  int a[20],b[20],c[19],i,ans=0;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    scanf("%d",&b[i]);
  }
  for(i=0;i<n-1;i++){
    scanf("%d",&c[i]);
  }
 int old = a[0];
	for (int i = 0; i < n; ++i) {
		ans += b[a[i]-1];
		if (a[i] - old == 1) {
			ans += c[old - 1];
		}
		old = a[i];
 
	}
  printf("%d",ans);
  return 0;
}
