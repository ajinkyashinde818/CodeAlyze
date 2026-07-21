#include<stdio.h>
int main(){
  int n,i,j,k,b;
  char s[1010][1110]={};
  while(scanf("%d",&n),n){
    char s[1010][1110]={};
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++){
      for(j=0;s[i][j]=='.';j++)s[i][j]=' ';
      if(j)s[i][j-1]='+';
    }
    for(j=0;j<n;j++){
      b=-1;
      for(i=0;i<n;i++){
	if(s[i][j]-'+'&&s[i][j]-' ')b=-1;
	if(s[i][j]-'+')continue;
	if(b>-1){
	  for(k=b+1;k<i;k++)s[k][j]='|';
	}
	b=i;
      }
    }
    for(i=0;i<n;i++)printf("%s\n",s[i]);
  }
  return 0;
}
