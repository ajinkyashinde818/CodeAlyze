#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  char a[n][n];
  char b[m][m];
  int p,q,r,s;
  int flag=1;
  for(p=0;p<n;p++){
    for(q=0;q<n;q++){
      scanf(" %c",&a[p][q]);}
  }
  for(p=0;p<m;p++){
    for(q=0;q<m;q++){
      scanf(" %c",&b[p][q]);}
  }
  for(r=0;r<=n-m+1;r++){
    for(s=0;s<=n-m+1;s++){
      int o=1;
      for(p=r;p<r+m;p++){
	for(q=s;q<s+m;q++){
	  if(a[p][q]!=b[p-r][q-s]){
	    o=0;}
	}
      }
      if(o==1){
	flag=0;}
    }
  }
  
  if(flag==0){
    printf("Yes");}
  else{printf("No");}
  return 0;
}
