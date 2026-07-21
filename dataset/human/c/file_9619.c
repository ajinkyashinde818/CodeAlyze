#include<stdio.h>
int main(){
  int n,m,p[1010],g,i,j;
  char h[1010][10],s[10];
  while(scanf("%d %d",&n,&m),n){
    for(i=g=0;i<n;i++)scanf("%s %d",h[i],&p[i]);
    while(m--){
      scanf("%s",s);
      for(j=0;j<n;j++){
	for(i=0;i<8;i++){
	  if(h[j][i]=='*')continue;
	  if(h[j][i]-s[i])break;
	}
	if(i==8)g+=p[j];
      }
    }
    printf("%d\n",g);
  }
  return 0;
}
