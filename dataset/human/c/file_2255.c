#include<stdio.h>
#define N 1000

char map[1001][1001];

int main(){
  int n,i,j,k,l,max,e;
  while(1){
    scanf("%d",&n);
    if(!n) break;
    for(i=0;i<n;i++){
      scanf("%s",map+i);
      map[i][n]='*';
    }
    for(i=0;i<n;i++) map[n][i]='*';
    for(i=0,max=0;i<n-max;i++){
      for(j=0;j<n-max;j++){
	if(map[i][j]=='.'){
	  for(k=2;1;k++){
	    for(l=0;l<k;l++){
	      if(map[k-1+i][l+j]=='*'||map[l+i][k-1+j]=='*') goto find;
	    }
	  }
	find:
	  k--;
	  if(max<k) max=k;
	}
      }
    }
    printf("%d\n",max);
  }
  return 0;
}
