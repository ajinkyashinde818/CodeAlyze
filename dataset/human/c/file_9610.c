#include<stdio.h>
#include<ctype.h>

typedef struct{
  char s[9];
  int p;
}lo;

int match(int p,char *m){
  int i,n;
  for(i=7,n=p;i>-1;i--,n/=10){
    if(isdigit(m[i])){
      if(n%10!=((int)m[i]-(int)'0')){
	return 0;
      }
    }
  }
  return 1;
}
int main(){
  int n,m,j,i,pr;
  lo ls[100];
  long long int ans;
  do{
    scanf("%d %d",&n,&m);
    if(!n&&!m) break;
    for(i=0;i<n;i++) scanf("%s %d",ls[i].s,&(ls[i].p));
    for(i=0,ans=0;i<m;i++){
      scanf("%d",&pr);
      for(j=0;j<n;j++){
	if(match(pr,ls[j].s)){
	  ans+=ls[j].p;
	  break;
	}
      }
    }
    printf("%ld\n",ans);
  }while(1);
  return 0;
}
