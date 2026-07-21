#include <stdio.h>
int main(void){
  int n,m,i,j,k,ans;
  char hit[100][9],num[1000][9];
  int lot[100];
  while(1){
    scanf("%d %d",&n,&m);
    if(!n)
      break;
    ans=0;
    for(i=0;i<n;i++)
      scanf("%s %d",hit[i],&lot[i]);
    for(i=0;i<m;i++)
      scanf("%s",num[i]);
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
	for(k=7;k>=0&&hit[i][k]!='*';k--){
	  if(hit[i][k]!=num[j][k])
	    break;
	}
	if(k<0||hit[i][k]=='*')
	  ans+=lot[i];
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
