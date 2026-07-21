#include<stdio.h>
int main(){
  int n,m,i,j,k,l;
  char a[100][100],b[100][100];
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)scanf("%s",a[i]);
  for(i=0;i<m;i++)scanf("%s",b[i]);
  for(i=0;i+m<=n;i++){
    for(j=0;j+m<=n;j++){
      for(k=0;k<m;k++){
	for(l=0;l<m;l++){
	  if(a[i+k][j+l]-b[k][l])goto NEXT;
	}
      }
      goto END;
    NEXT:;
    }
  }
  printf("No\n");
  return 0;
 END:;
  printf("Yes\n");
  return 0;
}
