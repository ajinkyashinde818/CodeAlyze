#include <stdio.h>
int m[1001][1001];
int main()
{
  int n,i,j,k,c,d;
  char s[1001];
  for(;;){
    scanf("%d",&n);
    if(n==0) break;
    for(i=0;i<n;i++){
      scanf("%s",s);
      c=0;
      for(j=0;j<n;j++){
	if(s[j] == '.') c++;
	else c=0;
	m[i][j] = c;
      }
    }
    c = 0;
    for(i=0;i<n;i++){
      for(j=n-1;j>=0;j--){
	if(m[i][j] > c){
	  d = m[i][j];
	  for(k=i+1;k<i+d;k++){
	    if(k >= n || m[k][j] < c) break;
	    if(d > m[k][j]) d = m[k][j];
	  }
	  if(k==i+d) c = d;
	}
      }
    }
    printf("%d\n",c);
  }
  return 0;
}
